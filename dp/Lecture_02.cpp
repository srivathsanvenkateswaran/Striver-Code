#include<bits/stdc++.h>
using namespace std;
// Climbing Stairs Problem 

int climbingStairsRecursion(int n)
{
    if(n==0) return 1;
    // Edge case of standing at the 0th stair
    if(n==1) return 1;
    // Edge case of standing at first stair to go to zero.

    int left = climbingStairsRecursion(n-1);
    int right = climbingStairsRecursion(n-2);

    return left + right;
}

int climbingStairsMemoization(int n, vector<int>& dp)
{
    if(n==0) return 1;
    if(n==1) return 1;

    if(dp[n] != -1) return dp[n];

    return dp[n] = climbingStairsMemoization(n-1, dp) + climbingStairsMemoization(n-2, dp);
}

int climbingStairsTabulation(int n)
{
    int dp[n+1] = {-1};

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main()
{
    int n=3;
    cout << climbingStairsRecursion(n) << endl;
    vector<int> dp(n+1, -1);
    cout << climbingStairsMemoization(n, dp) << endl;
    cout << climbingStairsTabulation(n) << endl;

    return 0;
}