#include<iostream>
using namespace std;

void printArr(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << "\n";  // or cout << *(arr+i) << "\n";
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18,20, 56};
    int n = sizeof(arr) / sizeof(int);
    printArr(arr, n);
    return 0;
}