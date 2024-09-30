#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) 
{
    int low = 0, high = size - 1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
         {
            return mid; 
        } else if (arr[mid] < target) 
        {
            low = mid + 1; 
        } else
         {
            high = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the value of array: "<<endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    cout << "Enter the target element: "<<endl;
    cin >> target;
    int result = binarySearch(arr, n, target);
    if (result != -1) 
    {
        cout << "Element found at index " << result << endl;
    } else 
    {
        cout << "Element not found" << endl;
    }

    return 0;
}