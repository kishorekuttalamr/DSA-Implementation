#include <iostream>
using namespace std;
int temp; // Temporary variable for swapping

void ascSelection(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i; // Index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j; // Update the index of the minimum element
            }
        }
        if (min != i) {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp; // Swap the minimum element with the current element
        }
    }
}

void descSelection(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max = i; // Index of the maximum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max]) {
                max = j; // Update the index of the maximum element
            }
        }
        if (max != i) {
            temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp; // Swap the maximum element with the current element
        }
    }
}

void printing(int arr[], int n) {
    cout << "SORTED ARRAY" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int n;
    cout << "enter the number of elements to be sorted" << endl;
    cin >> n;
    int arr[n];
    cout << "enter the elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ch;
    cout << "MENU" << endl;
    cout << "1.ASCENDING ORDER" << endl;
    cout << "2.DESCENDING ORDER" << endl;
    cin >> ch;
    switch (ch) {
    case 1:
        ascSelection(arr, n);
        printing(arr, n);
        break;
    case 2:
        descSelection(arr, n);
        printing(arr, n);
        break;
    default:
        cout<<"Invalid Choice";
    }
}
