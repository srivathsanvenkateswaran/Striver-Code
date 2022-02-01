#include <bits/stdc++.h>
using namespace std;

int mazeObstaclesRecursion(vector<vector<int>>& maze, int row, int col)
{
    if (maze[row][col] == -1)
        return 0;
    if (row == maze.size() - 1 && col == maze[0].size()-1)
        return 1;

    int down = 0;
    int right = 0;

    if (row < maze.size() - 1)
    {
        down = mazeObstaclesRecursion(maze, row + 1, col);
    }

    if (col < maze[0].size() - 1)
    {
        right = mazeObstaclesRecursion(maze, row, col + 1);
    }

    return down + right;
}

int mazeObstaclesMemoization(vector<vector<int>>& maze, int row, int col, vector<vector<int>>& dp)
{
    if (maze[row][col] == -1)
        return dp[row][col] = 0;
    if (row == maze.size() - 1 && col == maze[0].size()-1)
        return dp[row][col] = 1;

    if(dp[row][col] != -1)
        return dp[row][col];

    int down = 0;
    int right = 0;

    if (row < maze.size() - 1)
    {
        down = mazeObstaclesRecursion(maze, row + 1, col);
    }

    if (col < maze[0].size() - 1)
    {
        right = mazeObstaclesRecursion(maze, row, col + 1);
    }

    return dp[row][col] = down + right;
}

int mazeObstaclesTabulation(vector<vector<int>> maze)
{
    vector<vector<int>> dp(maze.size(), vector<int>(maze[0].size(), 0));

    for(int i=0; i<maze.size(); i++)
    {
        for(int j=0; j<maze[0].size(); j++)
        {
            if(maze[i][j] == -1) dp[i][j] = 0;
            else if(i==0 && j==0) dp[i][j] = 1;
            else
            {
                int up = 0;
                int left = 0;

                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];

                dp[i][j] = (up + left);
            }
        }
    }

    return dp[maze.size()-1][maze[0].size()-1];
}

int mazeObstaclesSpaceOptimized(vector<vector<int>> maze)
{
    vector<int> dp(maze[0].size(), 0);

    for(int i=0; i<maze.size(); i++)
    {
        vector<int> curr(maze[0].size(), 0);
        for(int j=0; j<maze[0].size(); j++)
        {
            if(maze[i][j] == -1) curr[j] = 0;
            else if(i==0 && j==0) curr[j] = 1;
            else
            {
                int up = 0;
                int left = 0;

                if(i>0) up = dp[j];
                if(j>0) left = curr[j-1];

                curr[j] = (up + left);
            }
        }
        dp = curr;
    }

    return dp[maze[0].size()-1];
}

int main() 
{
    vector<vector<int>> maze = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
        };

    cout << mazeObstaclesRecursion(maze, 0, 0) << '\n';

    vector<vector<int>> dp(maze.size(), vector<int>(maze[0].size(), -1));
    cout << mazeObstaclesMemoization(maze, 0, 0, dp) << '\n';

    cout << mazeObstaclesTabulation(maze) << '\n';

    cout << mazeObstaclesSpaceOptimized(maze) << '\n';

    return 0;
}