#include <bits/stdc++.h>
using namespace std;

int minimumCoinsRecursive(vector<int> arr, int target, int i)
{
    if(i == 0)
    {
        if(target%arr[0] == 0) return target/arr[0];
        return 1e9;
    }

    int notPick = minimumCoinsRecursive(arr, target, i-1);

    int pick = INT_MAX;
    if(arr[i] <= target)
    {
        pick = 1 + minimumCoinsRecursive(arr, target-arr[i], i);
    }

    return min(pick, notPick);
}

int minimumCoinsMemoization(vector<int> arr, int target, int i, vector<vector<int>>& dp)
{
    if(i == 0)
    {
        if(target%arr[0] == 0) return target/arr[0];
        return 1e9;
    }

    if(dp[i][target] != -1) return dp[i][target];

    int notPick = minimumCoinsMemoization(arr, target, i-1, dp);

    int pick = INT_MAX;
    if(arr[i] <= target)
    {
        pick = 1 + minimumCoinsMemoization(arr, target-arr[i], i, dp);
    }

    return dp[i][target] = min(pick, notPick);
}

int minimumCoinsTabulation(vector<int> arr, int target)
{
    vector<vector<int>> dp(arr.size(), vector<int>(target+1, 0));

    for(int t=0; t<=target; t++)
    {
        if(t%arr[0] == 0)
        {
            dp[0][t] = t/arr[0];
        }
        else
        {
            dp[0][t] = 1e9;
        }
    }

    for(int i=1; i<arr.size(); i++)
    {
        for(int t=0; t<=target; t++)
        {
            int notPick = dp[i-1][t];
            
            int pick = INT_MAX;
            if(arr[i] <= t)
            {
                pick = 1 + dp[i][t-arr[i]];
            }

            dp[i][t] = min(notPick, pick);
        }
    }

    return dp[arr.size()-1][target];
}

int minimumCoinsSpaceOptimized(vector<int> arr, int target)
{
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);

    for(int t=0; t<=target; t++)
    {
        if(t%arr[0] == 0)
        {
            prev[t] = t/arr[0];
        }
        else
        {
            prev[t] = 1e9;
        }
    }

    for(int i=1; i<arr.size(); i++)
    {
        for(int t=0; t<=target; t++)
        {
            int notPick = prev[t];

            int pick = INT_MAX;
            if(arr[i] <= t)
            {
                pick = 1 + curr[t-arr[i]];
            }

            curr[t] = min(notPick, pick);
        }
        prev = curr;
    }

    return prev[target];
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 7;

    cout << minimumCoinsRecursive(arr, target, arr.size()-1) << '\n';

    vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
    cout << minimumCoinsMemoization(arr, target, arr.size()-1, dp) << '\n';

    cout << minimumCoinsTabulation(arr, target) << '\n';

    cout << minimumCoinsSpaceOptimized(arr, target) << '\n';

    return 0;
}