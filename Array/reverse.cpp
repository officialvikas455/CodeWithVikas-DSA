#include<iostream>
using namespace std;

void copyArr(int *arr, int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}
void reverseArray(int *arr, int n){
    int *temp = new int[n]; 
    for(int i = 0; i < n; i++){
        temp[i] = arr[n - i - 1];
    }
    for(int i =  0; i< n; i++){
        arr[i] = temp[i];
    }
    delete[] temp;
    cout<<endl;

}
int main(){
    int arr[] = {5 , 10, 15, 20};
    int n = sizeof(arr)/sizeof(int);
    
    cout << "Original array: ";
    copyArr(arr, n);
    
    reverseArray(arr, n);
    
    cout << "Reversed array: ";
    copyArr(arr, n);
    
    return 0;
}
