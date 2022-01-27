#include <bits/stdc++.h>
using namespace std;

int frogKJumpsRecursion(vector<int> arr, int ind, int k)
{
    if(ind == 0) return 0;

    int minJumps = INT32_MAX;

    for(int i=1; i<=k; i++)
    {
        if(ind-i>=0)
        {
            int jump = frogKJumpsRecursion(arr, ind-i, k) + abs(arr[ind] - arr[ind-i]);

            minJumps = min(minJumps, jump);
        }
    }

    return minJumps;
}

int frogKJumpsMemoization(vector<int> arr, int ind, int k, vector<int>& dp)
{
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int minJumps = INT32_MAX;

    for(int i=1; i<=k; i++)
    {
        if(ind-i>=0)
        {
            int jump = frogKJumpsMemoization(arr, ind-i, k, dp) + abs(arr[ind] - arr[ind-i]);

            minJumps = min(minJumps, jump);
        }
    }

    return dp[ind] = minJumps;
}

int frogKJumpsTabulation(vector<int> arr, int k)
{
    vector<int> dp(arr.size(), INT32_MAX);
    
    dp[0] = 0;

    for(int ind=1; ind<arr.size(); ind++)
    {
        int minJumps = INT32_MAX;

        for(int i=1; i<=k; i++)
        {
            if(ind-i>=0)
            {
                int jump = dp[ind-i] + abs(arr[ind] - arr[ind-i]);
                minJumps = min(minJumps, jump);
            }
        }

        dp[ind] = minJumps;
    }

    return dp[arr.size()-1];
}

int main()
{
    vector<int> arr = {30, 10, 60, 10, 60, 50};

    cout << frogKJumpsRecursion(arr, arr.size()-1, 2) << endl;

    vector<int> dp(arr.size()+1, -1);

    cout << frogKJumpsMemoization(arr, arr.size()-1, 2, dp) << endl;

    cout << frogKJumpsTabulation(arr, 2) << endl;

    return 0;
}