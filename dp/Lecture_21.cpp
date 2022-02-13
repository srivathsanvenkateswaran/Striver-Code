#include <bits/stdc++.h>
using namespace std;
// https://youtu.be/b3GD8263-PQ?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY
// Same as Lecture 18

int targetSumMemoization(vector<int> arr, int target, int index, vector<vector<int>>& dp)
{
    if(index == 0)
    {
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || arr[0] == target) return 1;
        return 0;
    }

    if(dp[index][target] != -1) return dp[index][target];

    int notTake = targetSumMemoization(arr, target, index-1, dp);

    int take = 0;
    if(arr[index] <= target)
    {
        take = targetSumMemoization(arr, target-arr[index], index-1, dp);
    }

    return dp[index][target] = take + notTake;
}

int targetSumTabulation(vector<int> arr, int target)
{
    vector<vector<int>> dp(arr.size(), vector<int>(target+1, 0));
    
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;

    for(int i=1; i<arr.size(); i++)
    {
        for(int t=0; t<=target; t++)
        {
            int notTake = dp[i-1][t];

            int take = 0;
            if(arr[i] <= t)
            {
                take = dp[i-1][t-arr[i]];
            }

            dp[i][t] = take + notTake;
        }
    }

    return dp[arr.size()-1][target];
}

int targetSumSpaceOptimized(vector<int> arr, int target)
{
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);
    
    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;

    for(int i=1; i<arr.size(); i++)
    {
        for(int t=0; t<=target; t++)
        {
            int notTake = prev[t];

            int take = 0;
            if(arr[i] <= t)
            {
                take = prev[t-arr[i]];
            }

            curr[t] = take + notTake;
        }
        prev = curr;
    }

    return prev[target];
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};
    int t = 3;
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if(totalSum-t < 0 || (totalSum-t)%2) return false;
    int target = (totalSum-t)/2;

    vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
    cout << targetSumMemoization(arr, arr.size()-1, target, dp) << '\n';

    cout << targetSumTabulation(arr, target) << '\n';

    cout << targetSumSpaceOptimized(arr, target) << '\n';

    return 0;
}