#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int distinctSubsequencesRecursive(string one, string two, int oneInd, int twoInd)
{
    if(twoInd < 0) return 1;
    if(oneInd < 0) return 0;


    int notMatch = 0;
    int matchAndPick = 0;
    int matchAndNotPick = 0;  

    if(one[oneInd] == two[twoInd])
    {
        matchAndPick = distinctSubsequencesRecursive(one, two, oneInd-1, twoInd-1);
        matchAndNotPick = distinctSubsequencesRecursive(one, two, oneInd-1, twoInd);

        return (matchAndPick + matchAndNotPick)%mod;
    }
    else
    {
        notMatch = distinctSubsequencesRecursive(one, two, oneInd-1, twoInd);

        return (notMatch)%mod;
    }
}

int distinctSubsequencesMemoization(string& one, string& two, int oneInd, int twoInd, vector<vector<int>>& dp)
{
    if(twoInd < 0) return 1;
    if(oneInd < 0) return 0;

    if(dp[oneInd][twoInd] != -1) return dp[oneInd][twoInd];

    int notMatch = 0;
    int matchAndPick = 0;
    int matchAndNotPick = 0;  

    if(one[oneInd] == two[twoInd])
    {
        matchAndPick = distinctSubsequencesMemoization(one, two, oneInd-1, twoInd-1, dp);
        matchAndNotPick = distinctSubsequencesMemoization(one, two, oneInd-1, twoInd, dp);

        return dp[oneInd][twoInd] = (matchAndPick + matchAndNotPick)%mod;
    }
    else
    {
        notMatch = distinctSubsequencesMemoization(one, two, oneInd-1, twoInd, dp);

        return dp[oneInd][twoInd] = (notMatch)%mod;
    }
}

int distinctSupersequencesTabulation(string one, string two)
{
    vector<vector<int>> dp(one.size()+1, vector<int>(two.size()+1, 0));
    
    for(int i=0; i<=one.size(); i++)
    {
        dp[i][0] = 1;
    }

    for(int i=1; i<=one.size(); i++)
    {
        for(int j=1; j<=two.size(); j++)
        {
            int notMatch = 0;
            int matchAndPick = 0;
            int matchAndNotPick = 0;

            if(one[i-1] == two[j-1])
            {
                matchAndPick = dp[i-1][j-1];
                matchAndNotPick = dp[i-1][j];

                dp[i][j] = (matchAndPick + matchAndNotPick)%mod;
            }
            else
            {
                notMatch = dp[i-1][j];

                dp[i][j] = (notMatch)%mod;
            }
        }
    }

    return dp[one.size()][two.size()];
}

int distinctSupersequencesSpaceOptimization(string one, string two)
{
    vector<int> prev(one.size()+1, 0);
    vector<int> curr(two.size()+1, 0);
    
    prev[0] = 1;
    curr[0] = 1;

    for(int i=1; i<=one.size(); i++)
    {
        for(int j=1; j<=two.size(); j++)
        {
            int notMatch = 0;
            int matchAndPick = 0;
            int matchAndNotPick = 0;

            if(one[i-1] == two[j-1])
            {
                matchAndPick = prev[j-1];
                matchAndNotPick = prev[j];

                curr[j] = (matchAndPick + matchAndNotPick)%mod;
            }
            else
            {
                notMatch = prev[j];

                curr[j] = (notMatch)%mod;
            }
        }
        prev = curr;
    }

    return prev[two.size()];
}

int distinctSupersequencesSingleArraySpaceOptimization(string one, string two)
{
    vector<int> curr(two.size()+1, 0);
    
    curr[0] = 1;

    for(int i=1; i<=one.size(); i++)
    {
        for(int j=two.size(); j>=1; j--)
        {
            int notMatch = 0;
            int matchAndPick = 0;
            int matchAndNotPick = 0;

            if(one[i-1] == two[j-1])
            {
                matchAndPick = curr[j-1];
                matchAndNotPick = curr[j];

                curr[j] = (matchAndPick + matchAndNotPick)%mod;
            }
            else
            {
                notMatch = curr[j];

                curr[j] = (notMatch)%mod;
            }
        }
    }

    return curr[two.size()];
}

int main()
{
    string one = "babgbag";
    string two = "bag";

    cout << distinctSubsequencesRecursive(one, two, one.size()-1, two.size()-1) << '\n';

    vector<vector<int>> dp(one.size()+1, vector<int>(two.size()+1, -1));
    cout << distinctSubsequencesMemoization(one, two, one.size()-1, two.size()-1, dp) << '\n';

    cout << distinctSupersequencesTabulation(one, two) << '\n';

    cout << distinctSupersequencesSpaceOptimization(one, two) << '\n';

    cout << distinctSupersequencesSingleArraySpaceOptimization(one, two) << '\n';

    return 0;
}