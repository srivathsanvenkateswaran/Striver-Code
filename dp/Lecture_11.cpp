#include <bits/stdc++.h>
using namespace std;

int triangleMinimumSumRecursive(vector<vector<int>> triangle, int row, int col)
{
    if(row == triangle.size()-1) return triangle[row][col];

    int down = 0;
    int diagonal = 0;

    down = triangle[row][col] + triangleMinimumSumRecursive(triangle, row+1, col);
    diagonal = triangle[row][col] + triangleMinimumSumRecursive(triangle, row+1, col+1);

    return min(down, diagonal);
}

int triangleMinimumSumMemoization(vector<vector<int>> triangle, int row, int col, vector<vector<int>>& dp)
{
    if(row == triangle.size()-1) return triangle[row][col];
    if(dp[row][col] != -1) return dp[row][col];

    int diagonal = 0;
    int down = 0;

    diagonal = triangle[row][col] + triangleMinimumSumMemoization(triangle, row+1, col+1, dp);
    down = triangle[row][col] + triangleMinimumSumMemoization(triangle, row+1, col, dp);

    return dp[row][col] = min(down, diagonal);
}

int triangleMinimumSumTabulation(vector<vector<int>> triangle)
{
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size(), 0));

    for(int i=triangle[triangle.size()-1].size()-1; i>=0; i--)
    {
        dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];
    }

    for(int i=triangle.size()-2; i>=0; i--)
    {
        for(int j=triangle[i].size()-1; j>=0; j--)
        {
            int diagonal = 0;
            int down = 0;

            diagonal = triangle[i][j] + dp[i+1][j+1];
            down = triangle[i][j] + dp[i+1][j];

            dp[i][j] = min(diagonal, down);
        }
    }

    return dp[0][0];
}

int triangleMinimumSumSpaceOptimized(vector<vector<int>> triangle)
{
    vector<int> prev(triangle.size(), 0);

    for(int i=triangle[triangle.size()-1].size()-1; i>=0; i--)
    {
        prev[i] = triangle[triangle.size()-1][i];
    }

    for(int i=triangle.size()-2; i>=0; i--)
    {
        vector<int> temp(triangle.size(), 0);
        for(int j=triangle[i].size()-1; j>=0; j--)
        {
            int diagonal = 0;
            int down = 0;

            diagonal = triangle[i][j] + prev[j+1];
            down = triangle[i][j] + prev[j];

            temp[j] = min(diagonal, down);
        }
        prev = temp;
    }

    return prev[0];
}

int main()
{
    vector<vector<int>> triangle = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };

    cout << triangleMinimumSumRecursive(triangle, 0, 0) << '\n';

    vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size(), -1));
    cout << triangleMinimumSumMemoization(triangle, 0, 0, dp) << '\n';

    cout << triangleMinimumSumTabulation(triangle) << '\n';
    cout << triangleMinimumSumSpaceOptimized(triangle) << '\n';

    return 0;
}