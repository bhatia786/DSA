#include<iostream>
using namespace std;
void printdigit(int n){
    if(n==0){
        return;
    }
    int digit=n%10;
    n=n/10;
    printdigit(n);
    cout<<digit<<" ";
    
}

int main(){
    int n;
    cin>>n;
    int i=1;
    printdigit(n);
}
