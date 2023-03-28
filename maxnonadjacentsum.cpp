#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
void solve(vector<int>& arr,int i,int& maxi,int sum){
    if(i>=arr.size()){
        maxi=max(sum,maxi);
        return;
    }
    //include
    solve(arr,i+2,maxi,sum+arr[i]);
    //exclude
    solve(arr,i+1,maxi,sum);
}
int main() {
  vector<int>arr{12,10,10,11};
  int i=0;
  int maxi=INT_MIN;
  int sum=0;
  solve(arr,i,maxi,sum);
  cout<<maxi;
}
