#include <bits/stdc++.h>
using namespace std;
// All permutations of String/Array 

void allPermutations(vector<int>& arr, vector<int> flag, vector<int> v)
{
    if(v.size() == arr.size())
    {
        for(int i=0; i<v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<arr.size(); i++)
    {
        if(flag[i])
        {
            flag[i] = 0;
            v.push_back(arr[i]);
            allPermutations(arr, flag, v);
            v.pop_back();
            flag[i] = 1;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> flag(n, 1);
    vector<int> v;

    allPermutations(arr, flag, v);

    return 0;
}