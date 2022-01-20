#include <bits/stdc++.h>
using namespace std;
// N Queens Problem

bool isSafeToPlace(int row, int col, vector<string> board, int n)
{
    int dupRow = row;
    int dupCol = col;

    while(row >= 0 && col >= 0)
    {
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    col = dupCol;
    row = dupRow;

    while(row < n && col >= 0)
    {
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    row = dupRow;
    col = dupCol;

    while(col >= 0)
    {
        if(board[row][col] == 'Q') return false;
        col--;
    }

    return true;
}

void NQueens(int col, vector<string> board, vector<vector<string>>& ans, int n)
{
    if(col == n)
    {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row<n; row++)
    {
        if(isSafeToPlace(row, col, board, n))
        {
            board[row][col] = 'Q';
            NQueens(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

void NQueensOptimized(int col, vector<string> board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n)
{
    if(col == n)
    {
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++)
    {
        if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col-row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1 + col-row] = 1;
            NQueensOptimized(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1 + col-row] = 0;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for(int i=0; i<n; i++)
    {
        board[i] = s;
    }

    NQueens(0, board, ans, n);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << '\n' << '\n';
    }

    vector<vector<string>> optimizedAns;
    vector<int> leftRow(n, 0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n - 1, 0);
    // We make use of hashing to optimize the checking process 
    NQueensOptimized(0, board, optimizedAns, leftRow, upperDiagonal, lowerDiagonal, n);

    for(int i=0; i<optimizedAns.size(); i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << optimizedAns[i][j] << " ";
        }
        cout << '\n' << '\n';
    }

    return 0;
}