#include <bits/stdc++.h>
using namespace std;

int maximumPathSumVariableStartingPointRecursion(vector<vector<int>> matrix, int row, int col)
{
    if(col < 0 || col >= matrix[0].size()) return -1e9;
    if(row == matrix.size()-1) return matrix[row][col];

    int down = matrix[row][col] + maximumPathSumVariableStartingPointRecursion(matrix, row+1, col);
    int leftDiagonal = matrix[row][col] + maximumPathSumVariableStartingPointRecursion(matrix, row+1, col-1);
    int rightDiagonal = matrix[row][col] + maximumPathSumVariableStartingPointRecursion(matrix, row+1, col+1);

    return max(down, max(leftDiagonal, rightDiagonal));
}

int maxPathSumVariableStartingPointRecursionHelper(vector<vector<int>> matrix)
{
    int currMax = 0;

    for(int i=0; i<matrix[0].size(); i++)
    {
        int curr = maximumPathSumVariableStartingPointRecursion(matrix, 0, i);
        currMax = max(curr, currMax);
    }

    return currMax;
}

int maximumPathSumVariableStartingPointMemoization(vector<vector<int>> matrix, int row, int col, vector<vector<int>>& dp)
{
    if(col < 0 || col >= matrix[0].size()) return -1e9;
    if(row == matrix.size()-1) return matrix[row][col];
    if(dp[row][col] != -1) return dp[row][col];

    int down = matrix[row][col] + maximumPathSumVariableStartingPointMemoization(matrix, row+1, col, dp);
    int leftDiagonal = matrix[row][col] + maximumPathSumVariableStartingPointMemoization(matrix, row+1, col-1, dp);
    int rightDiagonal = matrix[row][col] + maximumPathSumVariableStartingPointMemoization(matrix, row+1, col+1, dp);

    return dp[row][col] = max(down, max(leftDiagonal, rightDiagonal));
}

int maxPathSumVariableStartingPointMemoizationHelper(vector<vector<int>> matrix)
{
    int currMax = 0;

    for(int i=0; i<matrix[0].size(); i++)
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int curr = maximumPathSumVariableStartingPointMemoization(matrix, 0, i, dp);
        currMax = max(curr, currMax);
    }

    return currMax;
}

int maxPathSumVariableStartingPointTabulation(vector<vector<int>> matrix)
{
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

    for(int i=0; i<matrix[0].size(); i++)
    {
        dp[matrix.size()-1][i] = matrix[matrix.size()-1][i];
    }

    for(int i=matrix.size()-2; i>=0; i--)
    {
        for(int j=matrix[0].size()-1; j>=0; j--)
        {
            int down = matrix[i][j];
            int leftDiagonal = matrix[i][j];
            int rightDiagonal = matrix[i][j];

            down += dp[i+1][j];

            if(j-1 >= 0)
            {
                leftDiagonal += dp[i+1][j-1];
            }
            else
            {
                leftDiagonal += (-1e9);
            }

            if(j+1 < matrix[0].size())
            {
                rightDiagonal += dp[i+1][j+1];
            }
            else 
            {
                rightDiagonal += (-1e9);
            }

            dp[i][j] = max(down, max(leftDiagonal, rightDiagonal));
        }
    }

    return *max_element(dp[0].begin(), dp[0].end());
}

int maxPathSumVariableStartingPointSpaceOptimization(vector<vector<int>> matrix)
{
    vector<int> next(matrix[0].size(), -1);

    for(int i=0; i<matrix[0].size(); i++)
    {
        next[i] = matrix[matrix.size()-1][i];
    }

    int curr = 0;

    for(int i=matrix.size()-2; i>=0; i--)
    {
        vector<int> temp(next.size(), 0);
        for(int j=matrix[0].size()-1; j>=0; j--)
        {
            int down = matrix[i][j];
            int leftDiagonal = matrix[i][j];
            int rightDiagonal = matrix[i][j];

            down += next[j];

            if(j-1 >= 0)
            {
                leftDiagonal += next[j-1];
            }
            else
            {
                leftDiagonal += (-1e9);
            }

            if(j+1 < matrix[0].size())
            {
                rightDiagonal += next[j+1];
            }
            else 
            {
                rightDiagonal += (-1e9);
            }

            curr = max(down, max(leftDiagonal, rightDiagonal));
            temp[j] = curr;
        }
        next = temp;
    }

    return *max_element(next.begin(), next.end());
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}
    };

    cout << maxPathSumVariableStartingPointRecursionHelper(matrix) << '\n';
    cout << maxPathSumVariableStartingPointMemoizationHelper(matrix) << '\n';
    cout << maxPathSumVariableStartingPointTabulation(matrix) << '\n';
    cout << maxPathSumVariableStartingPointSpaceOptimization(matrix) << '\n';

    return 0;
}