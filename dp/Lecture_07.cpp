#include <bits/stdc++.h>
using namespace std;

int returnMax(vector<int> arr, int lastDay)
{
    int maxi = INT_MIN;

    for(int i=0; i<arr.size(); i++)
    {
        if(i == lastDay) continue;
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

int ninjaTrainingRecursive(vector<vector<int>> arr, int day, int lastDay)
{
    if(day == 0) return returnMax(arr[day], lastDay);

    vector<int> val(3, -1);

    for (int i=0; i<arr[day].size(); i++)
    {
        if(lastDay == i) continue;
        val[i] = arr[day][i] + ninjaTrainingRecursive(arr, day - 1, i);
    }

    return *max_element(val.begin(), val.end());
}

int ninjaTrainingMemoization(vector<vector<int>> arr, int day, int lastDay, vector<vector<int>>& dp)
{
    if(dp[day][lastDay] != -1) return dp[day][lastDay];
    if(day == 0) return dp[day][lastDay] = returnMax(arr[day], lastDay);

    vector<int> val(3, -1);

    for(int i=0; i<arr[day].size(); i++)
    {
        if(lastDay == i) continue;
        val[i] = arr[day][i] + ninjaTrainingMemoization(arr, day-1, i, dp);
    }

    return dp[day][lastDay] = *max_element(val.begin(), val.end());
}

int ninjaTrainingTabulation(vector<vector<int>> arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(4, -1));
    
    for(int i=0; i<dp[0].size(); i++)
    {
        dp[0][i] = returnMax(arr[0], i);
    }

    for(int day=1; day<arr.size(); day++)
    {
        for(int last=0; last<=3; last++)
        {
            int maxi = INT_MIN;
            for(int task=0; task<arr[day].size(); task++)
            {
                if(task != last)
                {
                    int points = arr[day][task] + dp[day-1][task];
                    maxi = max(maxi, points);
                }
            }
            dp[day][last] = maxi;
        }
    }

    return dp[dp.size()-1][dp[0].size()-1];
    // Initial Call made to the recursion 
}

int ninjaTrainingSpaceOptimized(vector<vector<int>> arr)
{
    vector<int> dp(4, -1);
    for(int i=0; i<dp.size(); i++)
    {
        dp[i] = returnMax(arr[0], i);
    }

    for(int day=1; day<arr.size(); day++)
    {
        vector<int> dum(4, -1);
        for(int last=0; last<4; last++)
        {
            int maxi = INT_MIN;
            for(int task=0; task<arr[day].size(); task++)
            {
                if(task != last)
                {
                    int points = arr[day][task] + dp[task];
                    maxi = max(maxi, points);
                }
            }
            dum[last] = maxi;
        }
        dp = dum;
    }

    return dp[dp.size()-1];
}

int main()
{
    // vector<vector<int>> arr = {
    //     {1, 2, 5},
    //     {3, 1, 3},
    //     {3, 3, 3}};

    vector<vector<int>> arr = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}};

    cout << ninjaTrainingRecursive(arr, arr.size()-1, arr[0].size()) << '\n';

    vector<vector<int>> dp(arr.size(), vector<int>(4, -1));

    cout << ninjaTrainingMemoization(arr, arr.size()-1, arr[0].size(), dp) << '\n';

    cout << ninjaTrainingTabulation(arr) << '\n';
    cout << ninjaTrainingSpaceOptimized(arr) << '\n';

    return 0;
}