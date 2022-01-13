#include <bits/stdc++.h>
using namespace std;

int power(int x, int y)
{
    if(y == 0) return 1;
    return x*power(x, y-1);
}

int gcd(int a, int b, int s)
{
    if(s == 1) return 1;
    if(a%s == 0 && b%s == 0) return s;
    else return gcd(a, b, s-1);
}

int countNumberOfDigits(int n)
{
    if(n<10) return 1;
    return 1+countNumberOfDigits(n/10);
}

int main()
{
    cout << power(5, 3) << '\n';
    cout << gcd(5, 3, max(5, 3)) << '\n';
    cout << countNumberOfDigits(12345) << '\n';

    return 0;
}