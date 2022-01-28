#include <bits/stdc++.h>
using namespace std;

int maxSumNonAdjacentRecursive(vector<int> arr, int ind)
{
    if(ind == 0) return arr[ind];
    if(ind < 0) return 0;

    int left = arr[ind] + maxSumNonAdjacentRecursive(arr, ind-2);
    int right = maxSumNonAdjacentRecursive(arr, ind-1);

    return max(left, right);
}

int maxSumNonAdjacentMemoization(vector<int> arr, int ind, vector<int>& dp)
{
    if(ind == 0) return arr[ind];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int left = arr[ind] + maxSumNonAdjacentMemoization(arr, ind-2, dp);
    int right = maxSumNonAdjacentMemoization(arr, ind-1, dp);

    return dp[ind] = max(left, right);
}

int maxSumNonAdjacentTabulation(vector<int> arr)
{    
    vector<int> dp(arr.size(), -1);

    dp[0] = arr[0];

    for(int i=1; i<arr.size(); i++)
    {
        int left = INT_MIN;
        int right = INT_MIN;

        left = arr[i];

        if(i-2 >= 0)
        {
            left += dp[i-2];
        }
        
        right = dp[i-1];

        dp[i] = max(left, right);
    }

    return dp[arr.size()-1];
}

int maxSumNonAdjacentSpaceOptimization(vector<int> arr)
{    
    int curr = arr[0];
    int prev = 0;

    for(int i=1; i<arr.size(); i++)
    {
        int left = INT_MIN;
        int right = INT_MIN;

        left = arr[i];

        if(i-2 >= 0)
        {
            left += prev;
        }
        
        right = curr;

        prev = curr;
        curr = max(left, right);
    }

    return curr;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 4};

    cout << maxSumNonAdjacentRecursive(arr, arr.size()-1) << '\n';

    vector<int> dp(arr.size(), -1);
    cout << maxSumNonAdjacentMemoization(arr, arr.size()-1, dp) << '\n';

    cout << maxSumNonAdjacentTabulation(arr) << '\n';
    
    cout << maxSumNonAdjacentSpaceOptimization(arr) << '\n';

    return 0;
}