#include <bits/stdc++.h>
using namespace std;

int ninjaAndHisFriendsRecursive(vector<vector<int>> grid, int aliceRow, int aliceCol, int bobRow, int bobCol)
{
    if(aliceCol < 0 || aliceCol >= grid[0].size() || bobCol < 0 || bobCol >= grid[0].size()) return -1e9;
    if(aliceRow == grid.size()-1)
    {
        if(aliceCol != bobCol)
        {
            return grid[aliceRow][aliceCol] + grid[bobRow][bobCol];
        }
        else
        {
            return grid[aliceRow][aliceCol];
        }
    }

    int maxi = INT_MIN;

    for(int alice=-1; alice<2; alice++)
    {
        for(int bob=-1; bob<2; bob++)
        {
            int curr = grid[aliceRow][aliceCol];
            if(aliceCol != bobCol)
            {
                curr += grid[bobRow][bobCol];
            }

            curr += ninjaAndHisFriendsRecursive(grid, aliceRow+1, aliceCol+alice, bobRow+1, bobCol+bob);
            maxi = max(maxi, curr);
        }
    }

    return maxi;
}

int ninjaAndHisFriendsMemoization(vector<vector<int>> grid, int aliceRow, int aliceCol, int bobCol, vector<vector<vector<int>>>& dp)
{
    if(aliceCol < 0 || aliceCol >= grid[0].size() || bobCol < 0 || bobCol >= grid[0].size()) return -1e9;

    if(aliceRow == grid.size()-1)
    {
        if(aliceCol == bobCol)
        {
            return grid[aliceRow][aliceCol];
        }
        else
        {
            return grid[aliceRow][aliceCol] + grid[aliceRow][bobCol];
        }
    }

    if(dp[aliceRow][aliceCol][bobCol] != -1) return dp[aliceRow][aliceCol][bobCol];

    int maxi = INT_MIN;

    for(int alice=-1; alice<=1; alice++)
    {
        for(int bob=-1; bob<=1; bob++)
        {
            int curr;
            if(aliceCol == bobCol)
            {
                curr = grid[aliceRow][aliceCol] + ninjaAndHisFriendsMemoization(grid, aliceRow+1, aliceCol+alice, bobCol+bob, dp);
            }
            else
            {
                curr = grid[aliceRow][aliceCol] + grid[aliceRow][bobCol] + ninjaAndHisFriendsMemoization(grid, aliceRow+1, aliceCol+alice, bobCol+bob, dp);
            }
            maxi = max(maxi, curr);
        }
    }

    return dp[aliceRow][aliceCol][bobCol] = maxi;
}

int ninjaAndHisFriendsTabulation(vector<vector<int>>& grid)
{
    vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), 0)));

    for(int alice=0; alice<grid[0].size(); alice++)
    {
        for(int bob=0; bob<grid[0].size(); bob++)
        {
            if(alice == bob)
            {
                dp[grid.size()-1][alice][bob] = grid[grid.size()-1][alice];
            }
            else
            {
                dp[grid.size()-1][alice][bob] = grid[grid.size()-1][alice] + grid[grid.size()-1][bob];
            }
        }
    }

    for(int row=grid.size()-2; row>=0; row--)
    {
        for(int aliceCol=0; aliceCol<grid[0].size(); aliceCol++)
        {
            for(int bobCol=0; bobCol<grid[0].size(); bobCol++)
            {
                int maxi = INT_MIN;

                for(int alice=-1; alice<2; alice++)
                {
                    for(int bob=-1; bob<2; bob++)
                    {
                        int curr;
                        if(aliceCol == bobCol)
                        {
                            curr = grid[row][aliceCol];
                        }
                        else
                        {
                            curr = grid[row][aliceCol] + grid[row][bobCol];
                        }

                        if(bobCol+bob >=0 && bobCol+bob < grid[0].size() && aliceCol+alice >= 0 && aliceCol+alice < grid[0].size())
                        {
                            curr += dp[row+1][aliceCol+alice][bobCol+bob];
                        }
                        else
                        {
                            curr += -1e9;
                        }
                        maxi = max(maxi, curr);
                    }
                }
                dp[row][aliceCol][bobCol] = maxi;
            }
        }
    }
    return dp[0][0][grid[0].size()-1];
}

int main()
{
    vector<vector<int>> grid = {
        {2, 3, 1, 2}, 
        {3, 4, 2, 2}, 
        {5, 6, 3, 5}
    };

    cout << ninjaAndHisFriendsRecursive(grid, 0, 0, 0, grid[0].size()-1) << '\n';

    vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
    cout << ninjaAndHisFriendsMemoization(grid, 0, 0, grid[0].size()-1, dp) << '\n';

    cout << ninjaAndHisFriendsTabulation(grid) << '\n';
    
    return 0;
}