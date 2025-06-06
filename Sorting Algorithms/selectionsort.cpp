#include<iostream>
using namespace std;
void selectionsort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);

    }
}
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[6] = {5, 1, 4, 2, 8, 0};
    cout << "Before sorting: ";
    print(arr, 6);
    
    selectionsort(arr, 6);
    
    cout << "After sorting: ";
    print(arr, 6);
    return 0;
}