#include<iostream>
using namespace std;
void insertionsort(int arr[], int n){
    for(int i=1; i<n; i++){
       int  curr = arr[i];
       int prev = i-1;

        while(prev>=0 && arr[prev]>curr){
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main(){
    int arr[6] = {5, 1, 4, 2, 8, 0};
    cout << "Before sorting: ";
    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    insertionsort(arr, 6);

    cout << "After sorting: ";
    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}