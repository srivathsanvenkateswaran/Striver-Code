#include <bits/stdc++.h>
using namespace std;
// https://youtu.be/zoilQD1kYSg?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY

int mod = (int)(1e9 + 7);

int numberOfPartitionsWithGivenDifferenceMemoization(vector<int> arr, int target, int index, vector<vector<int>>& dp)
{
    if(index == 0)
    {
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || arr[0] == target) return 1;
        return 0;
    }

    if(dp[index][target] != -1) return dp[index][target];

    int notTake = numberOfPartitionsWithGivenDifferenceMemoization(arr, target, index-1, dp);

    int take = 0;
    if(arr[index] <= target)
    {
        take = numberOfPartitionsWithGivenDifferenceMemoization(arr, target-arr[index], index-1, dp);
    }

    return dp[index][target] = (take + notTake)%mod;
}

int numberOfPartitionsWithGivenDifferenceTabulation(vector<int> arr, int target)
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

int numberOfPartitionsWithGivenDifferenceSpaceOptimized(vector<int> arr, int target)
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

            curr[t] = (take + notTake)%mod;
        }
        prev = curr;
    }

    return prev[target];
}

int main()
{
    vector<int> arr = {5, 2, 6, 4};

    int difference = 3;
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if(totalSum-difference < 0 || (totalSum-difference)%2) return false;
    int target = (totalSum-difference)/2;

    vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
    cout << numberOfPartitionsWithGivenDifferenceMemoization(arr, target, arr.size()-1, dp) << '\n';

    cout << numberOfPartitionsWithGivenDifferenceTabulation(arr, target) << '\n';

    cout << numberOfPartitionsWithGivenDifferenceSpaceOptimized(arr, target) << '\n';

    return 0;
}