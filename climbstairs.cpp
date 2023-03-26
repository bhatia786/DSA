#include <iostream>
using namespace std;
int solve(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    int ans=solve(n-1)+solve(n-2);
    return ans;
}

int main() {
    int n=3;
    int ans=solve(n);
    cout<<"the no. of ways in which stairs can be climbed "<<ans;
}
