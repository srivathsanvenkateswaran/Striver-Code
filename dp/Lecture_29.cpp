#include <bits/stdc++.h>
using namespace std;

int minimumInsertionsToMakeAStringPalindrome(string str)
{
    string strRev = str;
    reverse(strRev.begin(), strRev.end());

    vector<vector<int>> dp(str.size()+1, vector<int>(str.size()+1, 0));

    for(int i=1; i<=str.size(); i++)
    {
        for(int j=1; j<=str.size(); j++)
        {
            int equal = INT_MIN;
            int notEqualLeft = INT_MIN;
            int notEqualRight = INT_MIN;

            if(str[i-1] == strRev[j-1])
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

    return str.size() - dp[str.size()][str.size()];
}

int main()
{
    string str = "zukcmbwsva";

    cout << minimumInsertionsToMakeAStringPalindrome(str) << '\n';

    return 0;
}