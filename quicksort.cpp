#include <iostream>
#include<vector>
using namespace std;
int partition(vector<int>& arr,int s,int e){
    int pivotIndex=s;
    int pivotElement=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivotElement){
            count++;
        }
    }
    int rightIndex=s+count;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex=rightIndex;
    // left me chote right me bade
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivotElement){
            i++;
        }
        while(arr[j]>pivotElement){
            j--;
        }
        // two cases
        if(i<pivotIndex&&j>pivotIndex){
            swap(arr[i],arr[j]);
        }
    }
    return pivotIndex;

}
void quickSort(vector<int>& arr,int s,int e){
    if(s>=e){
        return;
    }
    int p= partition(arr,s,e); // partition logic gives pivot index
    // recursive calls
    //left
    quickSort(arr,s,p-1);
    //right
    quickSort(arr,p+1,e);

}
int main() {
  vector<int>arr{10,20,30,8,8,8,8,8,1,1,1,1,1,3,4,20,50,2};
  int n=arr.size();
  int s=0;
  int e=n-1;
  quickSort(arr,s,e);
  for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
  }
}
