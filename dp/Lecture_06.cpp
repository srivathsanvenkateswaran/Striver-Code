#include <bits/stdc++.h>
using namespace std;

int houseRobberRecursiveUtil(vector<int> arr, int ind, int first)
{
    if(ind == first) return arr[first];
    if(ind < first) return 0;

    int left = arr[ind] + houseRobberRecursiveUtil(arr, ind-2, first);
    int right = houseRobberRecursiveUtil(arr, ind-1, first);

    return max(left, right);
}

int houseRobberRecursive(vector<int> arr, int ind)
{
    return max(houseRobberRecursiveUtil(arr, ind, 1), houseRobberRecursiveUtil(arr, ind-1, 0));
}

int houseRobberMemoizationUtil(vector<int> arr, int ind, int first, vector<int> dp)
{
    if(ind == first) return arr[first];
    if(ind < first) return 0;

    if(dp[ind] != -1) return dp[ind];

    int left = arr[ind] + houseRobberRecursiveUtil(arr, ind-2, first);
    int right = houseRobberRecursiveUtil(arr, ind-1, first);

    return dp[ind] = max(left, right);
}

int houseRobberMemoization(vector<int> arr, int ind)
{
    vector<int> dp(arr.size(), -1);

    return max(houseRobberMemoizationUtil(arr, ind, 1, dp), houseRobberMemoizationUtil(arr, ind-1, 0, dp));
}

int houseRobberTabulationUtil(vector<int> arr)
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

int houseRobberTabulation(vector<int> arr)
{
    vector<int> withoutFirst, withoutLast;

    for(int i=0; i<arr.size(); i++)
    {
        if(i)
        {
            withoutFirst.push_back(arr[i]);
        }
        if(i != arr.size()-1)
        {
            withoutLast.push_back(arr[i]);
        }
    }

    return max(houseRobberTabulationUtil(withoutFirst), houseRobberTabulationUtil(withoutLast));
}

int houseRobberSpaceOptimizationUtil(vector<int> arr)
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

int houseRobberSpaceOptimization(vector<int> arr)
{
    vector<int> withoutFirst, withoutLast;

    for(int i=0; i<arr.size(); i++)
    {
        if(i)
        {
            withoutFirst.push_back(arr[i]);
        }
        if(i != arr.size()-1)
        {
            withoutLast.push_back(arr[i]);
        }
    }

    return max(houseRobberSpaceOptimizationUtil(withoutFirst), houseRobberSpaceOptimizationUtil(withoutLast));
}

int main()
{
    vector<int> arr = {2, 3, 2};

    cout << houseRobberRecursive(arr, arr.size()-1) << '\n';
    cout << houseRobberMemoization(arr, arr.size()-1) << '\n';
    cout << houseRobberTabulation(arr) << '\n';
    cout << houseRobberSpaceOptimization(arr) << '\n';

    return 0;
}