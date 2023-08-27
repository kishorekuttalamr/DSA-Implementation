#include <iostream>

using namespace std;

int binarySearch(const int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid; // Return the index where the target is found
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; // Return -1 if the target is not found
}

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements (sorted in ascending order): ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element to search for: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
