#include <bits/stdc++.h>
using namespace std;
// Subset sum 

void printVector(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void findCombinationSum(int arr[], int n, int i, int sum, vector<int>& v)
{
    if(n == i)
    {
        v.push_back(sum);
        return;
    }

    findCombinationSum(arr, n, i+1, sum+arr[i], v);
    findCombinationSum(arr, n, i+1, sum, v);
}

int main()
{
    int arr[] = {5, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> v;
    findCombinationSum(arr, n, 0, 0, v);
    sort(v.begin(), v.end());
    printVector(v);

    return 0;
}