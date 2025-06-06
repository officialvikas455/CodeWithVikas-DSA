#include<iostream>
using namespace std;

void selectionsort(int arr[], int n){
    for(int i = 0; i<n; i++){
        int minIdx = i;
        for(int j = i+1; j<n-1; j++){
            if(arr[j] > arr[minIdx]){
                minIdx = j;
            }
            swap(arr[i], arr[minIdx]);
        }
    }
    cout<<endl;
}
void print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}

int main(){
    int arr[10] = {3,6,2,1,8,7,4,5,3,1};
    cout << "Before sorting: ";
    print(arr, 10);
    
    selectionsort(arr, 10);
    
    cout << "After sorting: ";
    print(arr, 10);
    return 0;
}
