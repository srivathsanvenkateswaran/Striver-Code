#include <bits/stdc++.h>
using namespace std;

int fiboMemoization(int n, vector<int>& dp)
// O(N) O(N)+O(N)
{
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fiboMemoization(n-1, dp) + fiboMemoization(n-2, dp);
}

int fiboTabulation(int n, vector<int>& dp)
// O(N) O(N)
{
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int fiboOptimized(int n)
{
    if(n<=1) return n;
    int prevPrev = 0;
    int prev = 1;
    int curr;

    for(int i=2; i<=n; i++)
    {
        curr = prev + prevPrev;
        prevPrev = prev;
        prev = curr;
    }

    return curr;
}

int main()
{
    int n = 5;
    vector<int> dp(n+1, -1);

    cout << fiboMemoization(n, dp) << endl;
    cout << fiboTabulation(n, dp) << endl;
    cout << fiboOptimized(n) << endl;

    return 0;
}