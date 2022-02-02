#include <bits/stdc++.h>
using namespace std;

int minimumSumPathRecursive(vector<vector<int>> maze, int row, int col)
{
    if(row == 0 && col == 0) return maze[0][0];
    if(row<0 || col<0) return 1e9;

    int up = maze[row][col] + minimumSumPathRecursive(maze, row-1, col);
    int left = maze[row][col] + minimumSumPathRecursive(maze, row, col-1);

    return min(up, left);
}

int minimumSumPathMemoization(vector<vector<int>> maze, int row, int col, vector<vector<int>>& dp)
{
    if(row == 0 && col == 0) return maze[0][0];
    if(row<0 || col<0) return 1e9;

    if(dp[row][col] != -1) return dp[row][col];

    int up = maze[row][col] + minimumSumPathMemoization(maze, row-1, col, dp);
    int left = maze[row][col] + minimumSumPathMemoization(maze, row, col-1, dp);

    return dp[row][col] = min(up, left);
}

int minimumSumPathTabulation(vector<vector<int>> maze)
{
    vector<vector<int>> dp(maze.size(), vector<int>(maze[0].size(), 0));

    for(int i=0; i<maze.size(); i++)
    {
        for(int j=0; j<maze[0].size(); j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j] = maze[i][j];
            }
            else
            {
                int up = maze[i][j];

                if(i>0)
                {
                    up += dp[i-1][j];
                }
                else
                {
                    up += 1e9;
                }

                int left = maze[i][j];

                if(j>0)
                {
                    left += dp[i][j-1];
                }
                else 
                {
                    left += 1e9;
                }

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[maze.size()-1][maze[0].size()-1];
}

int minumumSumPathSpaceOptimization(vector<vector<int>> maze)
{
    vector<int> prev(maze[0].size(), 0);

    for(int i=0; i<maze.size(); i++)
    {
        vector<int> temp(maze[0].size(), 0);
        for(int j=0; j<maze[0].size(); j++)
        {
            if(i==0 && j==0)
            {
                temp[j] = maze[i][j];
                continue;
            }

            int up = maze[i][j];
            int left = maze[i][j];

            if(i>0)
            {
                up += prev[j];
            }
            else
            {
                up += 1e9;
            }

            if(j>0)
            {
                left += temp[j-1];
            }
            else
            {
                left += 1e9;
            }

            temp[j] = min(left, up);
        }
        prev = temp;
    }

    return prev[maze[0].size()-1];
}

int main()
{
    vector<vector<int>> maze = {
        {5, 9, 6},
        {11, 5, 2}
    };

    cout << minimumSumPathRecursive(maze, maze.size()-1, maze[0].size()-1) << '\n';

    vector<vector<int>> dp(maze.size(), vector<int>(maze[0].size(), -1));

    cout << minimumSumPathMemoization(maze, maze.size()-1, maze[0].size()-1, dp) << '\n';

    cout << minimumSumPathTabulation(maze) << '\n';
    
    cout << minumumSumPathSpaceOptimization(maze) << '\n';

    return 0;
}