#include <bits/stdc++.h>
using namespace std;

string KthPermutation(int n, int k)
{
    int fact = 1;
    // We need the factorial of n-1 for splitting segments.
    vector<int> numbers;
    for(int i=1; i<n; i++)
    {
        fact *= i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k--;

    while(numbers.size())
    {
        ans += to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+ k/fact);
        if(!numbers.size()) break;
        k %= fact;
        fact /= numbers.size();
    }

    return ans;
}

int main()
{
    int n = 4;
    int k = 17;

    cout << KthPermutation(n, k) << '\n';

    return 0;
}