#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChangeRecursive(vector<int> arr, int i, int target)
{
    if(i == 0)
    {
        if(target%arr[i] == 0) return 1;
        return 0;
    }

    long notPick = countWaysToMakeChangeRecursive(arr, i-1, target);

    long pick = 0;
    if(arr[i] <= target)
    {
        pick = countWaysToMakeChangeRecursive(arr, i, target-arr[i]);
    }

    return notPick + pick;
}

long countWaysToMakeChangeMemoization(vector<int> arr, int i, int target, vector<vector<long>>& dp)
{
    if(i == 0)
    {
        if(target%arr[i] == 0) return 1;
        return 0;
    }
    if(dp[i][target] != -1) return dp[i][target];

    long notPick = countWaysToMakeChangeMemoization(arr, i-1, target, dp);

    long pick = 0;
    if(arr[i] <= target)
    {
        pick = countWaysToMakeChangeMemoization(arr, i, target-arr[i], dp);
    }

    return dp[i][target] = notPick + pick;
}

long countWaysToChangeTabulation(vector<int> arr, int target)
{
    vector<vector<long>> dp(arr.size(), vector<long>(target+1, 0));

    for(int t=0; t<=target; t++)
    {
        if(t%arr[0] == 0)
        {
            dp[0][t] = 1;
        }
    }

    for(int i=1; i<arr.size(); i++)
    {
        for(int t=0; t<=target; t++)
        {
            long notPick = dp[i-1][t];

            long pick = 0;
            if(arr[i] <= t)
            {
                pick = dp[i][t-arr[i]];
            }

            dp[i][t] = pick + notPick;
        }
    }

    return dp[arr.size()-1][target];
}

long countWaysToChangeSpaceOptimized(vector<int> arr, int target)
{
    vector<long> prev(target+1, 0);
    vector<long> curr(target+1, 0);

    for(int t=0; t<=target; t++)
    {
        if(t%arr[0] == 0)
        {
            prev[t] = 1;
        }
    }

    for(int i=1; i<arr.size(); i++)
    {
        for(int t=0; t<=target; t++)
        {
            long notPick = prev[t];

            long pick = 0;
            if(arr[i] <= t)
            {
                pick = curr[t-arr[i]];
            }

            curr[t] = pick + notPick;
        }
        prev = curr;
    }

    return prev[target];
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 4;

    cout << countWaysToMakeChangeRecursive(arr, arr.size()-1, target) << '\n';

    vector<vector<long>> dp(arr.size(), vector<long>(target+1, -1));
    cout << countWaysToMakeChangeMemoization(arr, arr.size()-1, target, dp) << '\n';

    cout << countWaysToChangeTabulation(arr, target) << '\n';

    cout << countWaysToChangeSpaceOptimized(arr, target) << '\n';

    return 0;
}