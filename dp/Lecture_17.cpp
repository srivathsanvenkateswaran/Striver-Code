#include <bits/stdc++.h>
using namespace std;

int numberOfSubsetsWithSumKRecursive(vector<int> arr, int target, int index)
{
    if(target == 0) return 1;
    if(index == 0) return arr[0] == target;

    int notTake = numberOfSubsetsWithSumKRecursive(arr, target, index-1);

    int take = 0;
    if(arr[index] <= target)
    {
        take = numberOfSubsetsWithSumKRecursive(arr, target-arr[index], index-1);
    }

    return take + notTake;
}

int numberOfSubsetsWithSumKMemoization(vector<int> arr, int target, int index, vector<vector<int>>& dp)
{
    if(target == 0) return 1;
    if(index == 0) return arr[0] == target;

    if(dp[index][target] != -1) return dp[index][target];

    int notTake = numberOfSubsetsWithSumKMemoization(arr, target, index-1, dp);

    int take = 0;
    if(arr[index] <= target)
    {
        take = numberOfSubsetsWithSumKMemoization(arr, target-arr[index], index-1, dp);
    }

    return dp[index][target] = take + notTake;
}

int numberOfSubsetsWithSumKTabulation(vector<int> arr, int target)
{
    vector<vector<int>> dp(arr.size(), vector<int>(target+1, 0));
    
    for(int i=0; i<arr.size(); i++)
    {
        dp[i][0] = 1;
    }

    if(arr[0] <= target) dp[0][arr[0]] = 1;

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

int numberOfSubsetsWithSumKSpaceOptimized(vector<int> arr, int target)
{
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);
    
    prev[0] = 1;
    curr[0] = 1;

    if(arr[0] <= target) prev[arr[0]] = 1;
    if(arr[0] <= target) curr[arr[0]] = 1;

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
    vector<int> arr = {1, 2, 2, 3};
    // vector<int> arr = {2, 3};

    int target = 3;

    cout << numberOfSubsetsWithSumKRecursive(arr, target, arr.size()-1) << '\n';

    vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
    cout << numberOfSubsetsWithSumKMemoization(arr, target, arr.size()-1, dp) << '\n';

    cout << numberOfSubsetsWithSumKTabulation(arr, target) << '\n';

    cout << numberOfSubsetsWithSumKSpaceOptimized(arr, target) << '\n';

    return 0;
}