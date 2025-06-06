#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge(vector<string>& arr, int si, int mid, int ei) {
    vector<string> temp;

    int i = si;
    int j = mid + 1;

    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= ei) {
        temp.push_back(arr[j++]);
    }

    // Copy the sorted elements back into the original array
    for (int idx = si, x = 0; idx <= ei; idx++, x++) {
        arr[idx] = temp[x];
    }
}

void mergeSort(vector<string>& arr, int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

void printArr(const vector<string>& arr) {
    for (const auto& str : arr) {
        cout << str << " ";
    }
    cout << endl; // Add a newline for better output formatting
}

int main() {
    vector<string> arr = {"sun", "earth", "mars", "mercury"};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);
    printArr(arr);
    return 0;
}
