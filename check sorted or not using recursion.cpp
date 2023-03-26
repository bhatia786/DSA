#include <iostream>
#include<vector>
using namespace std;
bool checkSorted(vector<int>& arr,int i,int& n){
    if(i==n-1){
        return true;
    }
    if(arr[i]<=arr[i+1]&&i+1<n){
        return checkSorted(arr,i+1,n);
    }
    else{
        return false;
    }
}

int main() {
  vector<int>arr{1,2,3,5,2};
  int n=arr.size();
  int i=0;
  bool ans=checkSorted(arr,i,n);
  if(ans){
      cout<<"sorted"<<endl;
  }
  else{
      cout<<"not sorted";
  }
}
