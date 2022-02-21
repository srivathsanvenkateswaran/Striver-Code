#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsackRecursive(vector<int> profit, vector<int> weight, int i, int capacity)
{
    if(i == 0)
    {
        return profit[i] * (capacity/weight[i]);
    }

    int notPick = unboundedKnapsackRecursive(profit, weight, i-1, capacity);
    
    int pick = 0;
    if(capacity >= weight[i])
    {
        pick = profit[i] + unboundedKnapsackRecursive(profit, weight, i, capacity-weight[i]);
    }

    return max(pick, notPick);
}

int unboundedKnapsackMemoization(vector<int>& profit, vector<int>& weight, int i, int capacity, vector<vector<int>>& dp)
{
    if(i == 0)
    {
        return profit[i] * (capacity/weight[i]);
    }

    if(dp[i][capacity] != -1) return dp[i][capacity];

    int notPick = unboundedKnapsackMemoization(profit, weight, i-1, capacity, dp);
    
    int pick = 0;
    if(capacity >= weight[i])
    {
        pick = profit[i] + unboundedKnapsackMemoization(profit, weight, i, capacity-weight[i], dp);
    }

    return dp[i][capacity] = max(pick, notPick);
}

int unboundedKnapsackTabulation(vector<int> profit, vector<int> weight, int capacity)
{
    vector<vector<int>> dp(weight.size(), vector<int>(capacity+1, 0));

    for(int i=0; i<=capacity; i++)
    {
        dp[0][i] = profit[0] * (i/weight[0]);
    }

    for(int i=1; i<weight.size(); i++)
    {
        for(int c=0; c<=capacity; c++)
        {
            int notPick = dp[i-1][c];

            int pick = 0;
            if(c >= weight[i])
            {
                pick = profit[i] + dp[i][c-weight[i]];
            }

            dp[i][c] = max(pick, notPick);
        }
    }

    return dp[weight.size()-1][capacity];
}

int unboundedKnapsackSpaceOptimized(vector<int> profit, vector<int> weight, int capacity)
{
    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    for(int i=0; i<=capacity; i++)
    {
        prev[i] = profit[0] * (i/weight[0]);
    }

    for(int i=1; i<weight.size(); i++)
    {
        for(int c=0; c<=capacity; c++)
        {
            int notPick = prev[c];

            int pick = 0;
            if(c >= weight[i])
            {
                pick = profit[i] + curr[c-weight[i]];
            }

            curr[c] = max(pick, notPick);
        }
        prev = curr;
    }

    return prev[capacity];
}

int main()
{
    vector<int> profit = {5, 11, 13};
    vector<int> weight = {2, 4, 6};

    int capacity = 10;

    cout << unboundedKnapsackRecursive(profit, weight, weight.size()-1, capacity) << '\n';

    vector<vector<int>> dp(weight.size(), vector<int>(capacity+1, -1));
    cout << unboundedKnapsackMemoization(profit, weight, weight.size()-1, capacity, dp) << '\n';

    cout << unboundedKnapsackTabulation(profit, weight, capacity) << '\n';

    cout << unboundedKnapsackSpaceOptimized(profit, weight, capacity) << '\n';

    return 0;
}