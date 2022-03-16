#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};

    int leftMin = arr[0];
    int maxProfit = 0;

    for(int i=1; i<arr.size(); i++)
    {
        int profit = arr[i] - leftMin;
        maxProfit = max(profit, maxProfit);
        
        if(leftMin > arr[i])
        {
            leftMin = arr[i];
        }
    }

    cout << maxProfit << '\n';

    return 0;
}