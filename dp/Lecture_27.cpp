#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstringTabulation(string one, string two)
{
    vector<vector<int>> dp(one.size()+1, vector<int>(two.size()+1, 0));
    int ans = INT_MIN;

    for(int i=1; i<=one.size(); i++)
    {
        for(int j=1; j<=two.size(); j++)
        {
            if(one[i-1] == two[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main()
{
    string one = "abcjklp";
    string two = "acjkp";

    cout << longestCommonSubstringTabulation(one, two) << '\n';

    return 0;
}