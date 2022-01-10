#include <bits/stdc++.h>
using namespace std;
// Parameterised and Functional Recursion

int sumOfNFunctional(int N)
{
    if(N == 0) return 0;
    return N + sumOfNFunctional(N-1);
}

void sumOfNParameterised(int N, int sum)
{
    if(N == 0)
    {
        cout << sum;
        return;
    }
    sum += N;
    sumOfNParameterised(N-1, sum);
}

int factorialFunctional(int N)
{
    if(N == 1) return 1;
    return N * factorialFunctional(N-1);
}

void factorialParameterised(int fact, int N)
{
    if(N == 1)
    {
        cout << fact;
        return;
    }
    factorialParameterised(fact * N, N-1);
}

int main()
{
    cout << sumOfNFunctional(5);
    sumOfNParameterised(5, 0);
    cout << factorialFunctional(5);
    factorialParameterised(1, 5);
    return 0;
}