#include <iostream>
using namespace std;
int recursiveBinarySearch(int arr[], int left, int right, int target) 
{
    if (left > right) {
        return -1; 
    }

    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (target < arr[mid]) {
        return recursiveBinarySearch(arr, left, mid - 1, target);
    }
    return recursiveBinarySearch(arr, mid + 1, right, target);
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the sorted array:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    cout << "Enter the target element: ";
    cin >> target;
    int result = recursiveBinarySearch(arr, 0, n - 1, target);
    if (result != -1) 
    {
        cout << "Target element found at index: " << result << endl;
    } else 
    {
        cout << "Target element not found." << endl;
    }

    return 0;
}
