#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
int solve(vector<int>& arr,int i,int sum){
    int maxi=INT_MIN;
    if(i>=arr.size()){
        maxi=max(sum,maxi);
        return maxi;
    }
    int ans1=solve(arr,i+2,sum+arr[i]);
    int ans2=solve(arr,i+1,sum);
    return max(ans1,ans2);
}
int main() {
  vector<int>arr{1,3,5,7,10};
  int i=0;
  int sum=0;
  cout<<solve(arr,i,sum);
}
