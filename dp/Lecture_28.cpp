#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(string one)
{
    string oneRev = one; 
    reverse(oneRev.begin(), oneRev.end());

    vector<vector<int>> dp(one.size()+1, vector<int>(one.size()+1, 0));

    dp[0][0] = 0;

    for(int i=1; i<=one.size(); i++)
    {
        for(int j=1; j<=one.size(); j++)
        {
            int equal = INT_MIN;
            int notEqualLeft = INT_MIN;
            int notEqualRight = INT_MIN;

            if(one[i-1] == oneRev[j-1])
            {
                equal = 1 + dp[i-1][j-1];
            }
            else
            {
                notEqualLeft = dp[i-1][j];
                notEqualRight = dp[i][j-1];
            }

            dp[i][j] = max(equal, max(notEqualLeft, notEqualRight));
        }
    }

    return dp[one.size()][one.size()];
}

int main()
{
    string one = "bbabcbcab";

    cout << longestPalindromicSubsequence(one) << '\n';

    return 0;
}