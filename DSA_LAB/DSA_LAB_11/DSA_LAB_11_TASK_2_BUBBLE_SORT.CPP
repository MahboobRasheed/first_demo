#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n-1; i++) 
    {
        for(int j= 0; j<n-1; j++){
            if(arr[i]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
}
}
void printarray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int arr[] = {9,12,7,15,};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array: ";
    printarray(arr, n);
    bubbleSort(arr, n);
    cout << " bubble Sorted Array: ";
    printarray(arr, n);
return 0;
}