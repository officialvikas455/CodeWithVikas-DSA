#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>> board){
    int n = board.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

bool isSafe(vector<vector<char>> &board, int row, int col){
    int n = board.size();
    
    // Check vertical
    for(int i = 0; i < row; i++){
        if(board[i][col] == 'Q') return false;
    }

    // Check left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q') return false;
    }

    // Check right diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void nQueens(vector<vector<char>> &board, int row){
    int n = board.size();
    if(row == n){
        printBoard(board);
        return;
    }

    for(int col = 0; col < n; col++){
        if(isSafe(board, row, col)){
            board[row][col] = 'Q';
            nQueens(board, row + 1);
            board[row][col] = '.'; // backtrack
        }
    }
}

int main(){
    int n = 2; // You can change this to any N
    vector<vector<char>> board(n, vector<char>(n, '.'));

    nQueens(board, 0);

    return 0;
}