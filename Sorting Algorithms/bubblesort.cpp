#include<iostream>
using namespace std;

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    bool isSwap;
    for (int i = 0; i < n - 1; i++) {
        isSwap = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap) {
            break; // No swaps means the array is already sorted
        }
    }
}

int main() {
    int arr[6] = {5, 1, 4, 2, 8, 0};
    cout << "Before sorting: ";
    print(arr, 6);
    
    bubbleSort(arr, 6);
    
    cout << "After sorting: ";
    print(arr, 6);
    return 0;
}