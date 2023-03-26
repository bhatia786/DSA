#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
void findMin(vector<int>& arr,int i,int n,int& mini){
    if(i>=n){
        return;
    }
    if(arr[i]<mini){
        mini=min(arr[i],mini);
    }
    findMin(arr,i+1,n,mini);
}
void findMax(vector<int>& arr,int i,int n,int& maxi){
    if(i>=n){
        return;
    }
    if(arr[i]>maxi){
        maxi=max(arr[i],maxi);
    }
    findMax(arr,i+1,n,maxi);

}
int main() {
    vector<int>arr{22,45,23,5,65,89,32};
    int i=0;
    int n=arr.size();
    int maxi=INT_MIN;
    int mini=INT_MAX;
    findMax(arr,i,n,maxi);
    findMin(arr,i,n,mini);
    cout<<"maximum element is "<<maxi<<endl;
    cout<<"minimum element is "<<mini<<endl;
}
