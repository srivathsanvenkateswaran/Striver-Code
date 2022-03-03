#include <bits/stdc++.h>
using namespace std;


void printLongestCommonSubsequence(string s1, string s2)
{
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

    for(int i=0; i<=s1.size(); i++)
    {
        dp[i][0] = 0;
    }

    for(int i=0; i<=s2.size(); i++)
    {
        dp[0][i] = 0;
    }

    for(int one=1; one<=s1.size(); one++)
    {
        for(int two=1; two<=s2.size(); two++)
        {
            int equal = INT_MIN;
            int notEqualLeft = INT_MIN;
            int notEqualRight = INT_MIN;

            if(s1[one-1] == s2[two-1])
            {
                equal = 1 + dp[one-1][two-1];
            }
            else
            {
                notEqualLeft = dp[one-1][two];
                notEqualRight = dp[one][two-1];
            }

            dp[one][two] = max(equal, max(notEqualLeft, notEqualRight));
        }
    }

    int one = s1.size();
    int two = s2.size();

    string ans;

    while(one > 0 && two > 0)
    {
        if(s1[one-1] == s2[two-1])
        {
            ans += s1[one-1];
            one--;
            two--;
        }
        else
        {
            if(dp[one-1][two] > dp[one][two-1])
            {
                one--;
            }
            else 
            {
                two--;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}

int main()
{
    string s1 = "abcde";
    string s2 = "bdqek";

    printLongestCommonSubsequence(s1, s2);

    return 0;
}