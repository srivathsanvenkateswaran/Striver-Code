#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while(start<=end)
    {
        if(s[start++] != s[end--]) return false;
    }

    return true;
}

void palindromePartitioning(string s, int index, vector<string>& path, vector<vector<string>>& ans)
{
    if(index == s.size())
    {
        ans.push_back(path);
        return;
    }

    for(int i=index; i<s.size(); i++)
    {
        if(isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i-index+1));
            palindromePartitioning(s, i+1, path, ans);
            path.pop_back();
        }
    }
}

int main()
{
    string s = "aabb";
    vector<string> path;
    vector<vector<string>> ans;

    palindromePartitioning(s, 0, path, ans);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}