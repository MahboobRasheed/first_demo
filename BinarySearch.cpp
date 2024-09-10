#include<iostream>
using namespace std;
int binarySearch(int arr[],int size,int target){
    int low=0;
    int high=size-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[arr[mid]==target]){
            return mid;
        }
        if (arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        return -1;
    }
}
int main(){
    int arr[6];
    for(int i=0;i<=6;i++){
        cout<<"Enter the value of array"<<"at index:"<<i<<"\t";
        cin>>arr[i];
    }
    int size=sizeof(arr)/sizeof(arr[0]);
    int target;
    cout<<"Enter the value to be search"<<endl;
    cin>>target;
    int result=binarySearch(arr,size,target);

    if(result!=-1){
        cout<<"element"<<target<<"found at index"<<result<<endl;

    }
    else{
        cout<<"element"<<target<<"not found in the index"<<result<<endl;
    }
    return 0;
}