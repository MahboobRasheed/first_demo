#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() 
{
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    cout << "Enter the target element: ";
    cin >> target;
    int result = linearSearch(arr, n, target);
    if (result != -1)
     {
        cout << "Target element found at index: " << result << endl;
    } else 
    {
        cout << "Target element not found." << endl;
    }

    return 0;
}
