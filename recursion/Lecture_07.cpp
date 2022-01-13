#include <bits/stdc++.h>
using namespace std;
// Printing all, any one, count of subsequences with sum K

void printVector(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void printSubsequenceWithSumK(int arr[], int i, int size, vector<int> v, int sum, int curSum)
{
    if(i == size) 
    {
        if(sum == curSum) printVector(v);
        return;
    }

    v.push_back(arr[i]);
    printSubsequenceWithSumK(arr, i+1, size, v, sum, curSum+arr[i]);
    v.pop_back();
    printSubsequenceWithSumK(arr, i+1, size, v, sum, curSum);
}

bool printAnySubsequenceWithSumK(int arr[], int i, int size, vector<int> v, int sum, int curSum)
{
    if(i == size) 
    {
        if(sum == curSum) 
        {
            // condition satisfied
            printVector(v);
            return true;
        }
        // condition not satisfied 
        return false;
    }

    v.push_back(arr[i]);
    if(!printAnySubsequenceWithSumK(arr, i+1, size, v, sum, curSum+arr[i]))
    {
        v.pop_back();
        return printAnySubsequenceWithSumK(arr, i+1, size, v, sum, curSum);
    }
    return true;
}

int printCountOfSubsequenceWithSumK(int arr[], int i, int size, int sum, int curSum)
{
    if(i == size) 
    {
        if(sum == curSum) return 1;
        return 0;
    }

    int left = printCountOfSubsequenceWithSumK(arr, i+1, size, sum, curSum+arr[i]);
    int right = printCountOfSubsequenceWithSumK(arr, i+1, size, sum, curSum);
    return left + right;
}

int main()
{
    int arr[] = {17, 18, 6, 11, 2, 4};
    int sum = 6;
    vector<int> v;

    cout << "Any one subsequence: " << '\n';
    printAnySubsequenceWithSumK(arr, 0, sizeof(arr)/sizeof(arr[0]), v, sum, 0);
    cout << '\n' << "All subsequence: " << '\n';
    printSubsequenceWithSumK(arr, 0, sizeof(arr)/sizeof(arr[0]), v, sum, 0);
    cout << '\n' << "Number of subsequence: " << " " << printCountOfSubsequenceWithSumK(arr, 0, sizeof(arr)/sizeof(arr[0]), sum, 0) << '\n';

    return 0;
}