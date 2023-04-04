#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,bool>rowCheck;
unordered_map<int,bool>upperDiagonalCheck;
unordered_map<int,bool>bottomDiagonalCheck;
void printSolution(vector<vector<char>>& board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
}
bool isSafe(vector<vector<char>>& board,int row,int col,int n){
    if(rowCheck[row]==true){
        return false;
    }
    if(upperDiagonalCheck[n-1+col-row]==true){
        return false;
    }
    if(bottomDiagonalCheck[row+col]==true){
        return false;
    }
    return true;
}
void solve(vector<vector<char>>& board,int n,int col){
    if(col>=n){
        printSolution(board,n);
        cout<<endl;
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            rowCheck[row]=true;
            upperDiagonalCheck[n-1+col-row]=true;
            bottomDiagonalCheck[row+col]=true;
            solve(board,n,col+1);
            board[row][col]='-';
            rowCheck[row]=false;
            upperDiagonalCheck[n-1+col-row]=false;
            bottomDiagonalCheck[row+col]=false;
            }
    }
}
int main() {
    int n=5;
    vector<vector<char>>board(n,vector<char>(n,'-'));
    int col=0;
    solve(board,n,col);
}
