#include <iostream>
#include<vector>
using namespace std;
void merge(vector<int>& arr,int s,int e){
    int mid=s+(e-s)/2;
    int left=mid-s+1;
    int right=e-mid;
    int* leftarray=new int[left];
    int* rightarray=new int[right];
    int k=s;
    for(int i=0;i<left;i++){
        leftarray[i]=arr[k];
        k++;
    }
    k=mid+1;
    for(int j=0;j<right;j++){
        rightarray[j]=arr[k];
        k++;
    }
    int i=0;
    int j=0;
    int c=s;
    while(i<left&&j<right){
        if(leftarray[i]<=rightarray[j]){
            arr[c++]=leftarray[i++];
        }
        else{
            arr[c++]=rightarray[j++];
        }
    }
    while(i<left){
        arr[c++]=leftarray[i++];
    }
    while(j<right){
        arr[c++]=rightarray[j++];
    }
}
void mergeSort(vector<int>& arr,int s,int e){
    int mid=s+(e-s)/2;
    if(s>=e){
        return;
    }
    // left array sort karo
    mergeSort(arr,s,mid);
    // right Array sort kar
    mergeSort(arr,mid+1,e);
    // now merge two sorted arrays
    merge(arr,s,e);
}
int main() {
  vector<int>arr{2,-1,1 ,1,1,9,8};
  int s=0;
  int e=arr.size()-1;
  mergeSort(arr,s,e);
  for(int i=0;i<arr.size();i++){
      cout<<arr[i]<<" ";
  }
}
