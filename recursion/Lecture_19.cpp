#include <bits/stdc++.h>
using namespace std;
// Rat in a Maze problem.

void ratInAMaze(vector<vector<int>> maze, vector<string> &ans, string path, int row, int col, int size)
{
    if (row == size - 1 && col == size - 1)
    {
        ans.push_back(path);
        return;
    }

    if (row < size - 1)
    {
        // Down
        row += 1;
        if (maze[row][col])
        {
            maze[row - 1][col] = 0;
            ratInAMaze(maze, ans, path + "D", row, col, size);
            maze[row - 1][col] = 1;
        }
        row -= 1;
    }

    if (col > 0)
    {
        // Left
        col -= 1;
        if (maze[row][col])
        {
            maze[row][col + 1] = 0;
            ratInAMaze(maze, ans, path + "L", row, col, size);
            maze[row][col + 1] = 1;
        }
        col += 1;
    }

    if (col < size - 1)
    {
        // Right
        col += 1;
        if (maze[row][col])
        {
            maze[row][col - 1] = 0;
            ratInAMaze(maze, ans, path + "R", row, col, size);
            maze[row][col - 1] = 1;
        }
        col -= 1;
    }

    if (row > 0)
    {
        // Up
        row -= 1;
        if (maze[row][col])
        {
            maze[row + 1][col] = 0;
            ratInAMaze(maze, ans, path + "U", row, col, size);
            maze[row + 1][col] = 1;
        }
        row += 1;
    }
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    // vector<vector<int>> maze = {{1, 0},
    //                             {1, 0}};

    vector<string> ans;
    string path = "";

    if(maze[0][0])
    {
        ratInAMaze(maze, ans, path, 0, 0, maze.size());
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    if (!ans.size())
    {
        cout << -1;
    }

    cout << endl;
}