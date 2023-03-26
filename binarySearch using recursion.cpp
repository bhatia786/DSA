#include <iostream>
#include<vector>
using namespace std;
void binarySearch(vector<int>& arr,int key,int s,int e,int &ans){
    int mid=s+(e-s)/2;
    if(s>e){
        return;
    }
    if(arr[mid]==key){
        ans=mid;
    }
    if(arr[mid]>key){
        binarySearch(arr,key,s,mid-1,ans);
    }
    if(arr[mid]<key){
        binarySearch(arr,key,mid+1,e,ans);
    }
}

int main() {
    vector<int>arr{1,2,3,4,5,6};
    int key=7;
    int n=arr.size();
    int s=0;
    int e=n-1;
    int ans=-1;
    binarySearch(arr,key,s,e,ans);
    if(ans==-1){
        cout<<"not found"<<endl;
    }
    else{
        cout<<"found at index: "<<ans<<endl;
    }
}
