#include <iostream>

using namespace std;

int linearSearch(const int arr[], int size, int target)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == target)
        {
            return i; // Return the index where the target is found
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
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element to search for: ";
    cin >> target;

    int result = linearSearch(arr, size, target);

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