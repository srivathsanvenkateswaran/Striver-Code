#include <bits/stdc++.h>
using namespace std;

bool partitionEqualSubsetSumRecursion(vector<int> arr, int i, int target)
{
    if(target == 0) return true;
    if(i == 0) return arr[0] == target;

    bool notTake = partitionEqualSubsetSumRecursion(arr, i-1, target);
    
    bool take = false;
    if(target >= arr[i])
    {
        take = partitionEqualSubsetSumRecursion(arr, i-1, target-arr[i]);
    }

    return take || notTake;
}

bool partitionEqualSubsetSumMemoization(vector<int> arr, int i, int target, vector<vector<int>>& dp)
{
    if(target == 0) return true;
    if(i == 0) return arr[0] == target;

    if(dp[i][target] != -1) return dp[i][target];

    bool notTake = partitionEqualSubsetSumMemoization(arr, i-1, target, dp);

    bool take = false;
    if(target >= arr[i])
    {
        take = partitionEqualSubsetSumMemoization(arr, i-1, target-arr[i], dp);
    }

    return dp[i][target] = take || notTake;
}

bool partitionEqualSubsetSumTabulation(vector<int> arr, int target)
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

bool partitionEqualSubsetSumSpaceOptimized(vector<int> arr, int target)
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
    // vector<int> arr = {2, 3, 3, 3, 4, 5};
    vector<int> arr = {5, 6, 5, 11, 6};

    int sum = accumulate(arr.begin(), arr.end(), 0);

    if(sum%2 == 0)
    {
        cout << partitionEqualSubsetSumRecursion(arr, arr.size()-1, sum/2) << '\n';

        vector<vector<int>> dp(arr.size(), vector<int>((sum/2)+1, -1));

        cout << partitionEqualSubsetSumMemoization(arr, arr.size()-1, sum/2, dp) << '\n';

        cout << partitionEqualSubsetSumTabulation(arr, sum/2) << '\n';

        cout << partitionEqualSubsetSumSpaceOptimized(arr, sum/2) << '\n';
    }
    else
    {
        cout << false << '\n';
        cout << false << '\n';
        cout << false << '\n';
        cout << false << '\n';
    }

    return 0;
}