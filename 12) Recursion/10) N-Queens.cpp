#include<bits/stdc++.h>
using namespace std;

/* Method 1: Check all the possibilities whether we could place the queen in current cell or not!
    If possible, place the Queen and check for next column. 
    As, we are checking for each Queen again and again, this is not the efficient solution to solve 
    this question.
    TC:- O(N * N * N) => O(N^3), 
    where, O(N) is for Loop, O(N) is for recursive calls, O(N) is for checking whether we can place 
    the Queen in that cell or not!

   Method 2: We could replace the isSafe() method with Hashing by ananlyzing the patterns and use that
    for checking the possibility of placing the Queen or not in current cell!
    URL: https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/
*/

bool isSafe(int row, int col, vector<string> &board, int n) {
    int dupRow = row;
    int dupCol = col;
    
    // Upper Left Diagonal
    while(row >= 0 && col >= 0) {
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    row = dupRow;
    col = dupCol;
    
    // Down Left Diagonal
    while(row < n && col >= 0) {
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    
    row = dupRow;
    col = dupCol;
    // Left Vertical
    while(col >= 0) {
        if(board[row][col] == 'Q') return false;
        col--;
    }
    
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
    if(col == n) {
        ans.push_back(board);
        return;
    }
    for(int row=0; row<n; row++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string str(n, '.');
    for(int i=0; i<n; i++) board[i] = str;
    solve(0, board, ans, n);
    return ans;
}

int main() {

    return 0;
}