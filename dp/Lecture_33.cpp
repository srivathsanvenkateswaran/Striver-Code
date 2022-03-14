#include <bits/stdc++.h>
using namespace std;

int editDistanceRecursive(string& one, string& two, int oneInd, int twoInd)
{
    if(twoInd < 0)
    {
        return oneInd + 1;
    }
    if(oneInd < 0)
    {
        return twoInd + 1;
    }

    int match = INT_MAX;
    int notMatchReplace = INT_MAX;
    int notMatchRemove = INT_MAX;
    int notMatchInsert = INT_MAX;

    if(one[oneInd] == two[twoInd])
    {
        match = editDistanceRecursive(one, two, oneInd-1, twoInd-1);

        return match;
    }
    else
    {
        notMatchInsert = 1 + editDistanceRecursive(one, two, oneInd, twoInd-1);
        notMatchRemove = 1 + editDistanceRecursive(one, two, oneInd-1, twoInd);
        notMatchReplace = 1 + editDistanceRecursive(one, two, oneInd-1, twoInd-1);

        return min(notMatchInsert, min(notMatchRemove, notMatchReplace));
    }
}

int editDistanceMemoization(string& one, string& two, int oneInd, int twoInd, vector<vector<int>>& dp)
{
    if(twoInd < 0)
    {
        return oneInd + 1;
    }
    if(oneInd < 0)
    {
        return twoInd + 1;
    }

    if(dp[oneInd][twoInd] != -1) return dp[oneInd][twoInd];

    int match = INT_MAX;
    int notMatchReplace = INT_MAX;
    int notMatchRemove = INT_MAX;
    int notMatchInsert = INT_MAX;

    if(one[oneInd] == two[twoInd])
    {
        match = editDistanceMemoization(one, two, oneInd-1, twoInd-1, dp);

        return dp[oneInd][twoInd] = match;
    }
    else
    {
        notMatchInsert = 1 + editDistanceMemoization(one, two, oneInd, twoInd-1, dp);
        notMatchRemove = 1 + editDistanceMemoization(one, two, oneInd-1, twoInd, dp);
        notMatchReplace = 1 + editDistanceMemoization(one, two, oneInd-1, twoInd-1, dp);

        return dp[oneInd][twoInd] = min(notMatchInsert, min(notMatchRemove, notMatchReplace));
    }
}

int editDistanceTabulation(string one, string two)
{
    vector<vector<int>> dp(one.size()+1, vector<int>(two.size()+1, 0));

    for(int i=0; i<=one.size(); i++)
    {
        dp[i][0] = i;
    }

    for(int i=0; i<=two.size(); i++)
    {
        dp[0][i] = i;
    }

    for(int i=1; i<=one.size(); i++)
    {
        for(int j=1; j<=two.size(); j++)
        {
            int notMatchInsert = INT_MAX;
            int notMatchRemove = INT_MAX;
            int notMatchReplace = INT_MAX;

            if(one[i-1] == two[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                notMatchInsert = 1 + dp[i][j-1];
                notMatchRemove = 1 + dp[i-1][j];
                notMatchReplace = 1 + dp[i-1][j-1];

                dp[i][j] = min(notMatchInsert, min(notMatchRemove, notMatchReplace));
            }
        }
    }

    return dp[one.size()][two.size()];
}

int editDistanceSpaceOptimized(string one, string two)
{
    vector<int> prev(one.size()+1, 0);
    vector<int> curr(two.size()+1, 0);

    for(int i=0; i<=two.size(); i++)
    {
        prev[i] = i;
    }

    for(int i=1; i<=one.size(); i++)
    {
        curr[0] = i;
        for(int j=1; j<=two.size(); j++)
        {
            int notMatchInsert = INT_MAX;
            int notMatchRemove = INT_MAX;
            int notMatchReplace = INT_MAX;

            if(one[i-1] == two[j-1])
            {
                curr[j] = prev[j-1];
            }
            else
            {
                notMatchInsert = 1 + curr[j-1];
                notMatchRemove = 1 + prev[j];
                notMatchReplace = 1 + prev[j-1];

                curr[j] = min(notMatchInsert, min(notMatchRemove, notMatchReplace));
            }
        }
        prev = curr;
    }

    return prev[two.size()];
}

int main()
{
    string one = "horse";
    string two = "ros";

    cout << editDistanceRecursive(one, two, one.size()-1, two.size()-1) << '\n';

    vector<vector<int>> dp(one.size(), vector<int>(two.size(), -1));
    cout << editDistanceMemoization(one, two, one.size()-1, two.size()-1, dp) << '\n';

    cout << editDistanceTabulation(one, two) << '\n';

    cout << editDistanceSpaceOptimized(one, two) << '\n';

    return 0;
}