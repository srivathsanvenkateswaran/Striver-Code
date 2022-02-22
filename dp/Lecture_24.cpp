#include <bits/stdc++.h>
using namespace std;

int rodCuttingRecursive(vector<int> cost, int size, int i)
{
    if(i == 1) return cost[i-1] * size;

    int notCut = rodCuttingRecursive(cost, size, i-1);
    
    int cut = INT_MIN;
    if(size >= i)
    {
        cut = cost[i-1] + rodCuttingRecursive(cost, size-i, i);
    }

    return max(cut, notCut);
}

int rodCuttingMemoization(vector<int> cost, int size, int i, vector<vector<int>>& dp)
{
    if(i == 1) return cost[i-1] * size;

    if(dp[i-1][size] != -1) return dp[i-1][size];

    int notCut = rodCuttingMemoization(cost, size, i-1, dp);
    
    int cut = INT_MIN;
    if(size >= i)
    {
        cut = cost[i-1] + rodCuttingMemoization(cost, size-i, i, dp);
    }

    return dp[i-1][size] = max(cut, notCut);
}

int rodCuttingTabulation(vector<int> cost, int size)
{
    vector<vector<int>> dp(cost.size()+1, vector<int>(cost.size()+1, 0));

    for(int s=0; s<=size; s++)
    {
        dp[0][s] = s * cost[0];
    }

    for(int i=1; i<cost.size(); i++)
    {
        for(int s=0; s<=size; s++)
        {
            int notCut = dp[i-1][s];

            int cut = INT_MIN;
            if(s >= i+1)
            {
                cut = cost[i] + dp[i][s-i-1];
            }

            dp[i][s] = max(cut, notCut);
        }
    }

    return dp[cost.size()-1][cost.size()];
}

int rodCuttingSpaceOptimized(vector<int> cost, int size)
{
    vector<int> prev(size+1, 0);
    vector<int> curr(size+1, 0);

    for(int s=0; s<=size; s++)
    {
        prev[s] = s * cost[0];
    }

    for(int i=1; i<cost.size(); i++)
    {
        for(int s=0; s<=size; s++)
        {
            int notCut = prev[s];

            int cut = INT_MIN;
            if(s >= i+1)
            {
                cut = cost[i] + curr[s-i-1];
            }

            curr[s] = max(cut, notCut);
        }
        prev = curr;
    }

    return prev[cost.size()];
}

int main()
{
    vector<int> cost = {2, 5, 7, 8, 10};

    cout << rodCuttingRecursive(cost, cost.size(), cost.size()) << '\n';

    vector<vector<int>> dp(cost.size(), vector<int>(cost.size()+1, -1));
    cout << rodCuttingMemoization(cost, cost.size(), cost.size(), dp) << '\n';

    cout << rodCuttingTabulation(cost, cost.size()) << '\n';

    cout << rodCuttingSpaceOptimized(cost, cost.size()) << '\n';

    return 0;
}