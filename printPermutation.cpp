#include <iostream>
#include<vector>
using namespace std;
void printPermutation(string& str,int i,vector<string>& ans){
    if(i>=str.length()){
        ans.push_back(str);
        return;
    }
    for(int j=i;j<str.length();j++){
        swap(str[i],str[j]);
        printPermutation(str,i+1,ans);
        swap(str[i],str[j]);
    }
}
int main() {
 string str="pqrs";
 int i=0;
 vector<string>ans;
 printPermutation(str,i,ans);
 
 for(int i=0;i<ans.size();i++){
     cout<<ans[i]<<" ";
 } 
}
