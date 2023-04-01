//{ Driver Code Starts

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[],int s,int e,long long int& count){
        int mid=s+(e-s)/2;
        int len1=mid-s+1;
        int len2=e-mid;
        int* left=new int[len1];
        int* right=new int[len2];
        int k=s;
        for(int i=0;i<len1;i++){
            left[i]=arr[k++];
        }
        k=mid+1;
        for(int j=0;j<len2;j++){
            right[j]=arr[k++];
            }
        int i=0;
        int j=0;
        int c=s;
        while(i<len1&&j<len2){
            if(left[i]>right[j]){
                count=count+len1-i;
                j++;
            }
            else{
                i++;
            }
        int i=0;
        int j=0;
        while(i<len1&&j<len2){
            if(left[i]<=right[j]){
                arr[c++]=left[i++];
            }
            else{
                arr[c++]=right[j++];
            }
        }
        while(i<len1){
            arr[c++]=left[i++];
        }
        while(j<len2){
            arr[c++]=right[j++];
        }
        
    }
    void count2(long long arr[],int s,int e,long long int& count){
        int mid=s+(e-s)/2;
        if(s>=e){
            return;
        }
        count2(arr,s,mid,count);
        count2(arr,mid+1,e,count);
        merge(arr,s,e,count);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int count=0;
        int s=0;
        int e=N-1;
        count2(arr, s ,e, count);
        return count;
    }
};

