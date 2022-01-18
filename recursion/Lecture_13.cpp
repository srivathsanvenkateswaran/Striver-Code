#include <bits/stdc++.h>
using namespace std;
// All permutations of Array/String without Flag array.
// https://youtu.be/f2ic2Rsc9pU?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9

void printVector(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void allPermutationsWithoutFlag(vector<int> arr, int ind)
{
    if(ind == arr.size())
    {
        printVector(arr);
    }

    for(int i=ind; i<arr.size(); i++)
    {
        swap(arr[ind], arr[i]);
        allPermutationsWithoutFlag(arr, ind+1);
        swap(arr[ind], arr[i]);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};

    allPermutationsWithoutFlag(arr, 0);

    return 0;
}