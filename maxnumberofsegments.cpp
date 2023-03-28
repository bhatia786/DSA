#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
int solve(vector<int>& arr,int n){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        int ans=solve(arr,n-arr[i]);
        if(ans!=INT_MIN){
            maxi=max(ans+1,maxi);
        }
    }
    return maxi;
}
int main() {
  int n=9;
  int x=5;
  int y=2;
  int z=2;
  vector<int>arr{x,y,z};
  int ans=solve(arr,n);
  if(ans<0){
      cout<<0;
  }
  else{
      cout<<"maximum no. of segments using x,y,z= "<<ans;
  }
}
