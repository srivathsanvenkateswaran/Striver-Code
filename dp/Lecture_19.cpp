#include <bits/stdc++.h>
using namespace std;

int zeroOneKnapsackRecursive(vector<int> weight, vector<int> value, int bagWeight, int i)
{
    if(i == 0)
    {
        if(bagWeight >= weight[0]) return value[0];
        return 0;
    }

    int notPick = zeroOneKnapsackRecursive(weight, value, bagWeight, i-1);
    int pick = INT_MIN;

    if(weight[i] <= bagWeight)
    {
        pick = value[i] + zeroOneKnapsackRecursive(weight, value, bagWeight-weight[i], i-1);
    }

    return max(pick, notPick);
}

int zeroOneKnapsackMemoization(vector<int> weight, vector<int> value, int bagWeight, int i, vector<vector<int>>& dp)
{
    if(i == 0)
    {
        if(bagWeight >= weight[0]) return value[0];
        return 0;
    }

    if(dp[i][bagWeight] != -1) return dp[i][bagWeight];

    int notPick = zeroOneKnapsackMemoization(weight, value, bagWeight, i-1, dp);
    int pick = INT_MIN;

    if(weight[i] <= bagWeight)
    {
        pick = value[i] + zeroOneKnapsackMemoization(weight, value, bagWeight-weight[i], i-1, dp);
    }

    return dp[i][bagWeight] = max(pick, notPick);
}

int zeroOneKnapsackTabulation(vector<int> weight, vector<int> value, int bagWeight)
{
    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight+1, 0));

    for(int i=weight[0]; i<=bagWeight; i++)
    {
        dp[0][i] = value[0];
    }

    for(int i=1; i<weight.size(); i++)
    {
        for(int w=0; w<=bagWeight; w++)
        {
            int notTake = dp[i-1][w];
            int take = INT_MIN;
            
            if(weight[i] <= w)
            {
                take = value[i] + dp[i-1][w-weight[i]];
            }

            dp[i][w] = max(take, notTake);
        }
    }

    return dp[weight.size()-1][bagWeight];
}

int zeroOneKnapsackSpaceOptimized(vector<int> weight, vector<int> value, int bagWeight)
{
    vector<int> prev(bagWeight+1, 0);

    for(int i=weight[0]; i<=bagWeight; i++)
    {
        prev[i] = value[0];
    }

    for(int i=1; i<weight.size(); i++)
    {
        for(int w=bagWeight; w>=0; w--)
        {
            int notTake = prev[w];
            int take = INT_MIN;
            
            if(weight[i] <= w)
            {
                take = value[i] + prev[w-weight[i]];
            }

            prev[w] = max(take, notTake);
        }
    }

    return prev[bagWeight];
}

int main()
{
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int bagWeight = 5;

    cout << zeroOneKnapsackRecursive(weight, value, bagWeight, weight.size()-1) << '\n';

    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight+1, -1));
    cout << zeroOneKnapsackMemoization(weight, value, bagWeight, weight.size()-1, dp) << '\n';

    cout << zeroOneKnapsackTabulation(weight, value, bagWeight) << '\n';

    cout << zeroOneKnapsackSpaceOptimized(weight, value, bagWeight) << '\n';

    return 0;
}