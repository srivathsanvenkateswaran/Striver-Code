#include <bits/stdc++.h>
using namespace std;

int frogJumpRecursion(vector<int> arr, int index)
{
    if(index == 0) return 0;
    
    int left = INT32_MAX;
    int right = INT32_MAX;

    left = frogJumpRecursion(arr, index-1) + abs((arr[index]-arr[index-1]));
    if(index>1)
    {
        right = frogJumpRecursion(arr, index-2) + abs((arr[index]-arr[index-2]));
    }

    return min(left, right);
}

int frogJumpMemoization(vector<int> arr, int index, vector<int>& dp)
{
    if(index == 0) return 0;

    if(dp[index] != -1) return dp[index];

    int right = INT32_MAX;
    int left = INT32_MAX;

    left = frogJumpMemoization(arr, index-1, dp) + abs((arr[index]-arr[index-1]));
    if(index>1)
    {
        right = frogJumpMemoization(arr, index-2, dp) + abs((arr[index]-arr[index-2]));
    }
    return dp[index] = min(left, right);
}

int frogJumpTabulation(vector<int> arr)
{
    vector<int> dp(arr.size(), -1);

    dp[0] = 0;

    for(int i=1; i<arr.size(); i++)
    {
        int left = INT32_MAX;
        int right = INT32_MAX;

        left = abs((arr[i]-arr[i-1])) + dp[i-1];
        if(i>1)
        {
            right = abs((arr[i]-arr[i-2])) + dp[i-2];
        }

        dp[i] = min(left, right);
    }

    return dp[arr.size()-1];
}

int frogJumpSpaceOptimized(vector<int> arr)
{
    int cost = 0;
    int prevCost = 0;

    for(int i=1; i<arr.size(); i++)
    {
        int left = INT32_MAX;
        int right = INT32_MAX;

        left = abs((arr[i]-arr[i-1])) + cost;
        if(i>1)
        {
            right = abs((arr[i]-arr[i-2])) + prevCost;
        }
        
        prevCost = cost;
        cost = min(left, right);
    }

    return cost;
}

int main()
{
    vector<int> arr = {30, 10, 60, 10, 60, 50};

    cout << frogJumpRecursion(arr, arr.size()-1) << endl;

    vector<int> dp(arr.size()+1, -1);

    cout << frogJumpMemoization(arr, arr.size()-1, dp) << endl;

    cout << frogJumpTabulation(arr) << endl;

    cout << frogJumpSpaceOptimized(arr) << endl;

    return 0;
}