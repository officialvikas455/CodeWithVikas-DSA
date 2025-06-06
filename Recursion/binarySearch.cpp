#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int st = 0;
    int end = n-1;
    while(st <= end){
        int mid = (st + end)/2;
        if(arr[mid] == key ){
            return mid;
        }
        else if(arr[mid]>key){
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    binarySearch(arr, n, key);

}

int main(){
    int arr[9]={1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 7;
    int index = binarySearch(arr, 9, key);
    if(index == -1){
        cout<<"key not found"<<endl;
    }
    else{
        cout<<"key found at index : "<<index<<endl;
    }   
    return 0;
}