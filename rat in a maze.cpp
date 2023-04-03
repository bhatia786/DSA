#include <iostream>
#include<vector>
#include<string>
using namespace std;
bool isSafe(int maze[][3],int row,int col,int i,int j,bool visited[][3]){
    if((i>=0&&i<row) && (j>=0&&j<col) && (maze[i][j]==1) && (visited[i][j]==false)){
        return true;
    }
    return false;
}
void solve(int maze[][3],int row,int col,int i,int j,bool visited[][3],vector<string>& ans,string output){
    if(i==row-1&&j==col-1){
        ans.push_back(output);
        return;
    }
    //Down
    if(isSafe(maze,row,col,i+1,j,visited)){
        visited[i+1][j]=true;
        output.push_back('D');
        solve(maze,row,col,i+1,j,visited,ans,output);
        visited[i+1][j]=false;
        output.pop_back();
    }
    //left
    if(isSafe(maze,row,col,i,j-1,visited)){
        visited[i][j-1]=true;
        output.push_back('L');
        solve(maze,row,col,i,j-1,visited,ans,output);
        visited[i][j-1]=false;
        output.pop_back();
    }
    //right
    if(isSafe(maze,row,col,i,j+1,visited)){
        visited[i][j+1]=true;
        output.push_back('R');
        solve(maze,row,col,i,j+1,visited,ans,output);
        visited[i][j+1]=false;
        output.pop_back();
    }
    //up
    if(isSafe(maze,row,col,i-1,j,visited)){
        visited[i-1][j]=true;
        output.push_back('U');
        solve(maze,row,col,i-1,j,visited,ans,output);
        visited[i-1][j]=false;
        output.pop_back();
    }
    
}

int main() {
  int maze[3][3]={{1,0,0},{1,1,0},{1,1,1}};
  int row=3;
  int col=3;
  bool visited[3][3]={{1,0,0},{0,0,0},{0,0,0}};
  int i=0;
  int j=0;
  if(maze[i][j]==0){
      cout<<"No path"<<endl;
      return 0;
  }
  vector<string>ans;
  string output="";
  solve(maze,row,col,i,j,visited,ans,output);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  if(ans.size()==0){
      cout<<"no path"<<endl;
  }
  }
  
