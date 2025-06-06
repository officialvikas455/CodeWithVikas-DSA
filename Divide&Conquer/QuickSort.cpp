#include<iostream>
using namespace std;

// Function to print the array
void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl; // Added newline for better readability
}

// Function to partition the array
int partition(int arr[], int si, int ei){
    int i = si - 1; // Changed 'st' to 'si'
    int pivot = arr[ei];
    
    for(int j = si; j < ei; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);
    return i;
}

// Function to perform quicksort
void quickSort(int arr[], int si, int ei){
    if(si < ei){ // Changed 'si <= ei' to 'si < ei'
        int pivotIdx = partition(arr, si, ei);
        quickSort(arr, si, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, ei);
    }
}

int main(){
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;
    
    quickSort(arr, 0, n - 1); // Removed 'int' keyword
    printArr(arr, n); // Removed 'int' keyword
    
    return 0;
}
