#include <bits/stdc++.h>
using namespace std;
// Recursion on subsequences

void printVector(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void printAllSubsets(int ind, int arr[], int n, vector<int> ans)
// Choice based recursion
// TC: 2^n SC: n
{
    if(ind == n)
    {
        printVector(ans);
        return;
    }
    ans.push_back(arr[ind]); // Choice is to include 
    printAllSubsets(ind+1, arr, n, ans);
    ans.pop_back(); // Choice is to not include
    printAllSubsets(ind+1, arr, n, ans);
}

int main()
{
    int arr[] = {3, 1, 2};
    vector<int> ans;

    printAllSubsets(0, arr, sizeof(arr)/sizeof(arr[0]), ans);

    return 0;
}