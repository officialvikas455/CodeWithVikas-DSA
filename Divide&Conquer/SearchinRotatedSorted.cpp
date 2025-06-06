#include<iostream>
using namespace std;
// Function to search in a rotated sorted array
int Search(int arr[],int si, int ei, int tar){
    int mid = si + (ei - si) / 2;
     if(arr[mid] == tar){
        return mid;
   }
   if(arr[si] <= arr[mid]){
    if(arr[si] <= tar && tar <= arr[mid]){
        return Search(arr, si, mid - 1, tar);
    }
    else{ // right half
        return Search(arr, mid + 1, ei, tar);
    }
   }
   else{
    if(arr[mid] <= tar && tar <= arr[ei]){
        return Search(arr, mid + 1, ei, tar);
    }
    else{ // left half
        return Search(arr, si, mid - 1, tar);
    }
   }
}

int main(){
    int arr[6] = {4, 5, 6, 7, 0, 1};
    int n = 6;
    int tar = 0;
    int ans = Search(arr, 3, n - 1, tar);
    cout << "Element found at index: " << ans << endl;
    return 0;
}
