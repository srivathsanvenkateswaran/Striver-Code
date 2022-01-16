#include <bits/stdc++.h>
using namespace std;
// https://youtu.be/RIn3gOkbhQE?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

void printVector(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void uniqueSubset(int arr[], int n, int ind, vector<int> v, vector<vector<int>>& ans)
{
    // No base case because, for ind > n, the loop won't run. 
    ans.push_back(v);

    for(int i=ind; i<n; i++)
    {
        if(i>ind && arr[i]==arr[i-1]) continue;
        v.push_back(arr[i]);
        uniqueSubset(arr, n, ind+1, v, ans);
        v.pop_back();
    }
}

int main()
{
    int arr[] = {1, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> v;
    vector<vector<int>> ans;
    sort(arr, arr+n);
    uniqueSubset(arr, n, 0, v, ans);

    for(int i=0; i<ans.size(); i++)
    {
        printVector(ans[i]);
    }

    return 0;
}