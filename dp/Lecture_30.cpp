#include <bits/stdc++.h>
using namespace std;

int numberOfInsertionsOrDeletionsRequiredToConvertStringAToB(string one, string two)
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

    return (one.size() - dp[one.size()][two.size()]) + (two.size() - dp[one.size()][two.size()]);
}

int main()
{
    string one = "abcd";
    string two = "anc";

    cout << numberOfInsertionsOrDeletionsRequiredToConvertStringAToB(one, two) << '\n';

    return 0;
}