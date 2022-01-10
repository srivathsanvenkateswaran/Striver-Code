#include <bits/stdc++.h>
using namespace std;

void printName5Times(int count)
{
    if(count == 5) return;
    cout << "Srivathsan" << '\n';
    printName5Times(++count);
}

void print1ToN(int N, int count)
{
    if(count == N+1) return;
    cout << count << " ";
    print1ToN(N, ++count);
}

void printNTo1(int count)
{
    if(count == 0) return;
    cout << count << " ";
    printNTo1(--count);
}

void print1ToNBacktrack(int count)
{
    if(count == 0) return;
    print1ToNBacktrack(count-1);
    cout << count << " ";
}

void printNTo1Backtrack(int count, int N)
{
    if(count == N+1) return;
    printNTo1Backtrack(count+1, N);
    cout << count << " ";
}

int main()
{
    printName5Times(0);
    print1ToN(5, 1);
    printNTo1(5);
    print1ToNBacktrack(5);
    printNTo1Backtrack(1, 5);
    return 0;
}