#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplicationTabulation(vector<int> arr)
{
    int dp[arr.size()][arr.size()];

    for(int i=1; i<arr.size(); i++)
    {
        dp[i][i] = 0;
    }

    for(int i=arr.size()-1; i>=1; i--)
    {
        for(int j=i+1; j<arr.size(); j++)
        {
            int minOperations = 1e9;

            for(int k=i; k<j; k++)
            {
                int steps = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];

                minOperations = min(steps, minOperations);
            }

            dp[i][j] = minOperations;
        }
    }

    return dp[1][arr.size()-1];
}

int main()
{
    vector<int> arr = {10, 15, 20, 25};

    cout << matrixChainMultiplicationTabulation(arr) << '\n';

    return 0;
}