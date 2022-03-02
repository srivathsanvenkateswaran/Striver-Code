#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequenceRecursion(string s1, string s2, int one, int two)
{
    if(one < 0 || two < 0) return 0;

    int equal = INT_MIN;
    int notEqualLeft = INT_MIN;
    int notEqualRight = INT_MIN;

    if(s1[one] == s2[two])
    {
        equal = 1 + longestCommonSubsequenceRecursion(s1, s2, one-1, two-1);
    }
    else
    {
        notEqualLeft = longestCommonSubsequenceRecursion(s1, s2, one-1, two);notEqualRight = longestCommonSubsequenceRecursion(s1, s2, one, two-1);
    }

    return max(equal, max(notEqualLeft, notEqualRight));
}

int longestCommonSubsequenceMemoization(string s1, string s2, int one, int two, vector<vector<int>>& dp)
{
    if(one < 0 || two < 0) return 0;

    if(dp[one][two] != -1) return dp[one][two];

    int equal = INT_MIN;
    int notEqualLeft = INT_MIN;
    int notEqualRight = INT_MIN;

    if(s1[one] == s2[two])
    {
        equal = 1 + longestCommonSubsequenceMemoization(s1, s2, one-1, two-1, dp);
    }
    else
    {
        notEqualLeft = longestCommonSubsequenceMemoization(s1, s2, one-1, two, dp);notEqualRight = longestCommonSubsequenceMemoization(s1, s2, one, two-1, dp);
    }

    return dp[one][two] = max(equal, max(notEqualLeft, notEqualRight));
}

int longestCommonSubsequenceTabulation(string s1, string s2)
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

    return dp[s1.size()][s2.size()];
}

int longestCommonSubsequenceSpaceOptimized(string s1, string s2)
{
    vector<int> prev(s2.size()+1, 0);
    vector<int> curr(s2.size()+1, 0);

    for(int i=0; i<=s2.size(); i++)
    {
        prev[i] = 0;
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
                equal = 1 + prev[two-1];
            }
            else
            {
                notEqualLeft = prev[two];
                notEqualRight = curr[two-1];
            }

            curr[two] = max(equal, max(notEqualLeft, notEqualRight));
        }
        prev = curr;
    }

    return prev[s2.size()];
}

int main()
{
    string s1 = "adcbc";
    string s2 = "dcadb";

    cout << longestCommonSubsequenceRecursion(s1, s2, s1.size()-1, s2.size()-1) << '\n';

    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
    cout << longestCommonSubsequenceMemoization(s1, s2, s1.size()-1, s2.size()-1, dp) << '\n';

    cout << longestCommonSubsequenceTabulation(s1, s2) << '\n';

    cout << longestCommonSubsequenceSpaceOptimized(s1, s2) << '\n';

    return 0;
}