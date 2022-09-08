#include<bits/stdc++.h>
using namespace std;

bool isPossible(int row, int col, vector<vector<char>> &board, char ch) {
    for(int i=0; i<9; i++) {
        if(board[row][i] == ch) return false;
        if(board[i][col] == ch) return false;
        
        // for rectangular sub-matrix
        int tr = 3 * (row/3) + (i/3);
        int tc = 3 * (col/3) + (i%3);
        if(board[tr][tc] == ch) return false;
        
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board) {
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            if(board[i][j] == '.') {
                for(char ch='1'; ch<='9'; ch++) {
                    if(isPossible(i, j, board, ch)) {
                        board[i][j] = ch;
                        if(solveSudoku(board) == true) {
                            return true;
                        }
                        else {
                            board[i][j] = '.';
                        }                            
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>>board {
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };

    cout<<"Original Suduko is:\n";
    for(int i= 0; i< 9; i++) {
        for(int j= 0; j< 9; j++) {
            cout<<board[i][j]<<" ";
        }    
        cout<<"\n";
    }

    solveSudoku(board);

    cout<<"\nResultant Sudoko is:\n";   	
    for(int i= 0; i< 9; i++) {
        for(int j= 0; j< 9; j++) {
            cout<<board[i][j]<<" ";
        }    
        cout<<"\n";
    }
    return 0;
}