#include <iostream>
#include<vector>
using namespace std;
void printAns(vector<vector<char>>& board,int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<board[i][j]<<"  ";
    }
    cout<<endl;
  }
}
bool isSafe(vector<vector<char>>& board,int row,int col,int n){
  int i=row;
  int j=col;
  // left row
  while(j>=0){
    if(board[i][j]=='Q'){
      return false;
    }
    j--;
  }
  i=row;
  j=col;
  //upper left diagonal
  while(i>=0&&j>=0){
    if(board[i][j]=='Q'){
      return false;
    }
    i--;
    j--;
  }
  // bottom left diagonal
  i=row;
  j=col;
  while(i<n&&j>=0){
    if(board[i][j]=='Q'){
      return false;
    }
    i++;
    j--;
  }
  return true;
}
void solve(vector<vector<char>>& board,int col,int n){
  if(col>=n){
    printAns(board,n);
    cout<<endl;
    return;
  }
  for(int row=0;row<n;row++){
    if(isSafe(board,row,col,n)){
      board[row][col]='Q';
      solve(board,col+1,n);
      // backtrack
      board[row][col]='-';
    }
  }
}
int main() {
  int n=5;
  vector<vector<char>>board(n,vector<char>(n,'-'));
  int col=0;
  solve(board,col,n);
}
