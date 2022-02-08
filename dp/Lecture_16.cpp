#include <bits/stdc++.h>
using namespace std;
// https://youtu.be/GS_OqZb2CWc?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY
// Minimum Subset Sum Difference. 

int minimumSubsetSumDifference(vector<int> arr, int target)
{
    vector<bool> prev(target+1, false);
    vector<bool> curr(target+1, false);

    prev[0] = true;
    curr[0] = true;

    prev[arr[0]] = true;

    for(int i=1; i<arr.size(); i++)
    {
        for(int t=1; t<=target; t++)
        {
            bool notTake = prev[t];
            bool take = false;

            if(arr[i]<=t)
            {
                take = prev[t-arr[i]];
            }

            curr[t] = take || notTake;
        }
        prev = curr;
    }

    int left = target/2;
    int right = target/2+1;

    if(target%2 == 0 && prev[left])
    {
        return 0;
    }

    while(left > 0 && right <= target)
    {
        if(prev[left] && prev[right])
        {
            return right-left;
        }
        if(!prev[left])
        {
            left--;
        }
        if(!prev[right])
        {
            right++;
        }
    }

    return right-left;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    // vector<int> arr = {8, 6, 5};

    cout << minimumSubsetSumDifference(arr, accumulate(arr.begin(), arr.end(), 0)) << '\n';

    return 0;
}