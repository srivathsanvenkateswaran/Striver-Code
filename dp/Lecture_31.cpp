#include <bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string one, string two)
{
    vector<vector<int>> dp(one.size()+1, vector<int>(two.size()+1, 0));

    for(int i=1; i<=one.size(); i++)
    {
        for(int j=1; j<=two.size(); j++)
        {
            int equal = INT_MIN;
            int notEqualLeft = INT_MIN;
            int notEqualRight = INT_MIN;
            if(one[i-1] == two[j-1])
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

    string ans;

    int i=one.size(), j=two.size();

    while(i>0 && j>0)
    {
        if(one[i-1] == two[j-1])
        {
            ans += one[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            ans += one[i-1];
            i--;
        }
        else
        {
            ans += two[j-1];
            j--;
        }
    }

    while(i > 0)
    {
        ans += one[i-1];
        i--;
    }

    while(j > 0)
    {
        ans += two[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return one.size() + two.size() - dp[one.size()][two.size()];
}

int main()
{
    string one = "brute";
    string two = "groot";

    cout << shortestCommonSupersequence(one, two) << '\n';

    return 0;
}