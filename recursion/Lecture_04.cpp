#include <bits/stdc++.h>
using namespace std;
// Recursion on array and string

void reverseArray(int arr[], int left, int right)
{
    if(left >= right) return;
    swap(arr[left], arr[right]);
    reverseArray(arr, left+1, right-1);
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

void isPalindrome(string s, int left, int right)
{
    if(left > right)
    {
        cout << "Palindrome" << '\n';
        return;
    }

    if(s[left] != s[right])
    {
        cout << "Not Palindrome" << '\n';
        return;
    }
    else
    {
        isPalindrome(s, left+1, right-1);
    }
}

bool isPalindromeCheck(string s, int left, int right)
{
    if(left > right) return true; 
    if(s[left] != s[right]) return false; 
    else return isPalindromeCheck(s, left+1, right-1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    printArray(arr, sizeof(arr)/sizeof(arr[0]));

    string s = "racecar";
    isPalindrome(s, 0, s.size()-1);
    if(isPalindromeCheck(s, 0, s.size()-1))
    {
        cout << "Palindrome";
    }
    else 
    {
        cout << "Not Palindrome";
    }

    return 0;
}