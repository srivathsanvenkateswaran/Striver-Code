#include <bits/stdc++.h>
using namespace std;

int gridUniquePathRecursive(int row, int col, int maxRow, int maxCol)
{
    if(row == maxRow && col == maxCol) return 1;

    int down = 0;
    int right = 0;

    if(row<maxRow)
    {
        // We can move down 
        down = gridUniquePathRecursive(row+1, col, maxRow, maxCol);
    }

    if(col<maxCol)
    {
        // We can move right
        right = gridUniquePathRecursive(row, col+1, maxRow, maxCol);
    }

    return down + right;
}

int gridUniquePathMemoization(int row, int col, int maxRow, int maxCol, vector<vector<int>>& dp)
{
    if(dp[row][col] != -1) return dp[row][col];

    if(row == maxRow && col == maxCol) return dp[row][col] = 1;

    int down = 0;
    int right = 0;

    if(row<maxRow)
    {
        // We can move down 
        down = gridUniquePathMemoization(row+1, col, maxRow, maxCol, dp);
    }

    if(col<maxCol)
    {
        // We can move right
        right = gridUniquePathMemoization(row, col+1, maxRow, maxCol, dp);
    }

    return dp[row][col] = down + right;
}

int gridUniquePathTabulation(int maxRow, int maxCol)
{
    vector<vector<int>> dp(maxRow, vector<int>(maxCol, -1));

    for(int i=0; i<maxRow; i++)
    {
        dp[i][maxCol-1] = 1;
    }

    for(int i=0; i<maxCol; i++)
    {
        dp[maxRow-1][i] = 1;
    }

    for(int row=maxRow-2; row>=0; row--)
    {
        for(int col=maxCol-2; col>=0; col--)
        {
            dp[row][col] = dp[row+1][col] + dp[row][col+1];
        }
    }

    return dp[0][0];
}

int gridUniquePathSpaceOptimized(int maxRow, int maxCol)
{
    vector<int> dp(maxCol, 1);
    int curr = 0;

    for(int row=maxRow-2; row>=0; row--)
    {
        int nextRow = 1;
        for(int col=maxCol-2; col>=0; col--)
        {
            curr = nextRow + dp[col];
            dp[col] = curr;
            nextRow = curr;
        }
    }

    // To understand this, better visualize how the loop operates and compare it with the problem statement and above tabulation solution. 

    return curr;
}

int main()
{
    int maxRow = 3;
    int maxCol = 2;

    cout << gridUniquePathRecursive(0, 0, maxRow-1, maxCol-1) << '\n';

    vector<vector<int>> dp(maxRow, vector<int>(maxCol, -1));

    cout << gridUniquePathMemoization(0, 0, maxRow-1, maxCol-1, dp) << '\n';

    cout << gridUniquePathTabulation(maxRow, maxCol) << '\n';

    cout << gridUniquePathSpaceOptimized(maxRow, maxCol) << '\n';

    return 0;
}