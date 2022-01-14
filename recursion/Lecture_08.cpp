#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void combinationSum(int arr[], int n, int i, int target, vector<int> v, vector<vector<int>>& ans)
{
    if(target == 0)
    {
        ans.push_back(v);
        return;
    }
    if(n == i) return;

    if(arr[i] <= target)
    {
        v.push_back(arr[i]);
        combinationSum(arr, n, i, target-arr[i], v, ans);
        v.pop_back();
    }
    combinationSum(arr, n, i+1, target, v, ans);
}

vector<vector<int>> findCombinations(int arr[], int n, int target)
{
    vector<int> v;
    vector<vector<int>> ans;
    combinationSum(arr, n, 0, target, v, ans);

    return ans;
}

int main()
{
    int arr[] = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans;

    ans = findCombinations(arr, sizeof(arr)/sizeof(arr[0]), target);

    for(int i=0; i<ans.size(); i++)
    {
        printVector(ans[i]);
    }

    return 0;
}