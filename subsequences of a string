#include <iostream>
#include<vector>
using namespace std;
void solve(string str,string output,int i,int n,vector<string>& ch){
    if(i>=n){
        ch.push_back(output);
        return;
    }
    // exclude
    solve(str,output,i+1,n,ch);   //exclude mein output same rahega
    //include
    solve(str,output+str[i],i+1,n,ch); //include kar lia
}

int main() {
  string str="abc";
  string output="";
  int n=str.length();
  int i=0;
  vector<string>ch;
  solve(str,output,i,n,ch);
  for(int i=0;i<ch.size();i++){
      cout<<ch[i]<<endl;
  }
}
