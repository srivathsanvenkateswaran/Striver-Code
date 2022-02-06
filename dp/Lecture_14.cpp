#include <bits/stdc++.h>
using namespace std;

bool subsetSumEqualToTargetRecursion(vector<int> arr, int i, int target)
{
    if(target == 0) return true;
    if(i == 0) return arr[0] == target;

    bool notTake = subsetSumEqualToTargetRecursion(arr, i-1, target);
    
    bool take = false;
    if(target >= arr[i])
    {
        take = subsetSumEqualToTargetRecursion(arr, i-1, target-arr[i]);
    }

    return take || notTake;
}

bool subsetSumEqualToTargetMemoization(vector<int> arr, int i, int target, vector<vector<int>>& dp)
{
    if(target == 0) return true;
    if(i == 0) return arr[0] == target;

    if(dp[i][target] != -1) return dp[i][target];

    bool notTake = subsetSumEqualToTargetMemoization(arr, i-1, target, dp);

    bool take = false;
    if(target >= arr[i])
    {
        take = subsetSumEqualToTargetMemoization(arr, i-1, target-arr[i], dp);
    }

    return dp[i][target] = take || notTake;
}

bool subsetSumEqualToTargetTabulation(vector<int> arr, int target)
{
    vector<vector<bool>> dp(arr.size(), vector<bool>(target+1, false));

    for(int i=0; i<arr.size(); i++)
    {
        dp[i][0] = true;
        // target == 0 case 
    }
    dp[0][arr[0]] = true;

    for(int i=1; i<arr.size(); i++)
    {
        for(int t=1; t<=target; t++)
        {
            bool take = false;
            bool notTake = dp[i-1][t];

            if(t >= arr[i])
            {
                take = dp[i-1][t-arr[i]];
            }

            dp[i][t] = take || notTake;
        }
    }

    return dp[arr.size()-1][target];
}

bool subsetSumEqualToTargetSpaceOptimized(vector<int> arr, int target)
{
    vector<bool> prev(target+1, false);
    vector<bool> curr(target+1, false);

    prev[0] = true;
    curr[0] = true;

    prev[arr[0]] = true;

    for(int i=1; i<arr.size(); i++)
    {
        for(int t=1; t<=target; t++)
        {
            bool take = false;
            bool notTake = prev[t];

            if(t >= arr[i])
            {
                take = prev[t-arr[i]];
            }

            curr[t] = take || notTake;
        }
        prev = curr;
    }

    return prev[target];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int target = 4;

    cout << subsetSumEqualToTargetRecursion(arr, arr.size()-1, target) << '\n';

    vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));

    cout << subsetSumEqualToTargetMemoization(arr, arr.size()-1, target, dp) << '\n';

    cout << subsetSumEqualToTargetTabulation(arr, target) << '\n';

    cout << subsetSumEqualToTargetSpaceOptimized(arr, target) << '\n';

    return 0;
}