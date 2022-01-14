#include <bits/stdc++.h>
using namespace std;
// https://youtu.be/G1fRTGRxXU8?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

void printVector(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void findCombinations(int arr[], int n, int i, int target, vector<int>& v, vector<vector<int>>& ans)
{
    if(target == 0)
    {
        ans.push_back(v);
        return;
    }
    if(n == i) return;

    for(int j=i; j<n; j++)
    // Here we are selecting subsequences [manipulating the starting index]
    {
        if(j>i && arr[j]==arr[j-1]) continue;
        if(arr[j]>target) break;
        v.push_back(arr[j]);
        findCombinations(arr, n, j+1, target-arr[j], v, ans);
        v.pop_back();
    }
}

vector<vector<int>> findUniqueCombinations(int arr[], int n, int target)
{
    sort(arr, arr+n);
    vector<int> v;
    vector<vector<int>> ans;
    findCombinations(arr, n, 0, target, v, ans);
    return ans;
}

int main()
{
    int arr[] = {10,1,2,7,6,1,5};
    int target = 8;
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<vector<int>> ans;
    ans = findUniqueCombinations(arr, n, target);

    for(int i=0; i<ans.size(); i++)
    {
        printVector(ans[i]);
    }

    return 0;
}