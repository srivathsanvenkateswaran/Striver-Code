#include <bits/stdc++.h>
using namespace std;

bool wildcardMatchingRecursive(string& one, string& two, int oneInd, int twoInd)
{
    if(twoInd < 0)
    {
        for(int i=0; i<=oneInd; i++)
        {
            if(one[i] != '*')
            {
                return false;
            }
        }

        return true;
    }
    if(oneInd < 0)
    {
        if(twoInd >= 0) return false;
        return true;
    }

    if(one[oneInd] == two[twoInd] || one[oneInd] == '?')
    {
        return wildcardMatchingRecursive(one, two, oneInd-1, twoInd-1);
    }
    else if(one[oneInd] == '*')
    {
        bool includeInStar = wildcardMatchingRecursive(one, two, oneInd, twoInd-1);
        bool excludeInStar = wildcardMatchingRecursive(one, two, oneInd-1, twoInd);

        return includeInStar | excludeInStar;
    }
    return false;
}

bool wildcardMatchingMemoization(string& one, string& two, int oneInd, int twoInd, vector<vector<int>>& dp)
{
    if(twoInd < 0)
    {
        for(int i=0; i<=oneInd; i++)
        {
            if(one[i] != '*')
            {
                return false;
            }
        }

        return true;
    }
    if(oneInd < 0)
    {
        if(twoInd >= 0) return false;
        return true;
    }

    if(dp[oneInd][twoInd] != -1) return dp[oneInd][twoInd];

    if(one[oneInd] == two[twoInd] || one[oneInd] == '?')
    {
        return dp[oneInd][twoInd] = wildcardMatchingMemoization(one, two, oneInd-1, twoInd-1, dp);
    }
    else if(one[oneInd] == '*')
    {
        bool includeInStar = wildcardMatchingMemoization(one, two, oneInd, twoInd-1, dp);
        bool excludeInStar = wildcardMatchingMemoization(one, two, oneInd-1, twoInd, dp);

        return dp[oneInd][twoInd] = includeInStar | excludeInStar;
    }
    return dp[oneInd][twoInd] = false;
}

bool wildcardMatchingTabulation(string one, string two)
{
    vector<vector<bool>> dp(one.size()+1, vector<bool>(two.size()+1, false));

    dp[0][0] = true;
    
    for(int i=1; i<=two.size(); i++)
    {
        dp[0][i] = false;
    }

    for(int i=1; i<=one.size(); i++)
    {
        bool starFlag = true;
        for(int j=1; j<=i; j++)
        {
            if(one[j-1] != '*')
            {
                starFlag = false;
                break;
            }
        }

        dp[i][0] = starFlag;
    }

    for(int i=1; i<=one.size(); i++)
    {
        for(int j=1; j<=two.size(); j++)
        {
            if(one[i-1] == two[j-1] || one[i-1] == '?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(one[i-1] == '*')
            {
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
            }
            else dp[i][j] = false;
        }
    }

    return dp[one.size()][two.size()];
}

int main()
{
    string one = "ba*a?";
    string two = "baaabab";

    cout << wildcardMatchingRecursive(one, two, one.size()-1, two.size()-1) << '\n';

    vector<vector<int>> dp(one.size(), vector<int>(two.size(), -1));
    cout << wildcardMatchingMemoization(one, two, one.size()-1, two.size()-1, dp) << '\n';

    cout << wildcardMatchingTabulation(one, two) << '\n';

    return 0;
}