#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplicationRecursive(vector<int> arr, int i, int j)
{
    if(i == j) return 0;

    int minimumOperations = 1e9;

    for(int k=i; k<j; k++)
    {
        int curr = (arr[i-1] * arr[k] * arr[j]) + matrixChainMultiplicationRecursive(arr, i, k) + matrixChainMultiplicationRecursive(arr, k+1, j);

        minimumOperations = min(minimumOperations, curr);
    }

    return minimumOperations;
}

int matrixChainMultiplicationMemoization(vector<int> arr, int i, int j, vector<vector<int>>& dp)
{
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int minimumOperations = 1e9;

    for(int k=i; k<j; k++)
    {
        int steps = (arr[i-1] * arr[k] * arr[j]) + matrixChainMultiplicationMemoization(arr, i, k, dp) + matrixChainMultiplicationMemoization(arr, k+1, j, dp);

        minimumOperations = min(minimumOperations, steps);
    }

    return dp[i][j] = minimumOperations;
}

int main()
{
    vector<int> arr = {10, 15, 20, 25};

    cout << matrixChainMultiplicationRecursive(arr, 1, arr.size()-1) << '\n';

    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
    cout << matrixChainMultiplicationMemoization(arr, 1, arr.size()-1, dp) << '\n';

    return 0;
}