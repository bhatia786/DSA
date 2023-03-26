#include <iostream>
using namespace std;
void findkey(string str,char key,int i,int n,int& ans){
    if(i>=n){
        return;
    }
    if(str[i]==key){
        ans=i;
    }
    findkey(str,key,i+1,n,ans);
}

int main() {
    string str="chirag";
    char key='i';
    int ans=-1;
    int i=0;
    int n=str.length();
    findkey(str,key,i,n,ans);
    if(ans==-1){
        cout<<"not found"<<endl;
    }
    else{
        cout<<"found at "<<ans; 
    }
}
