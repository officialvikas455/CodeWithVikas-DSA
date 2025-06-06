#include<iostream>
using namespace std;
void countingsort(int arr[], int n){
    int freq[1000000] = {0};
    int minVal = INT_MAX, maxVal = INT_MIN;
    for(int i=0; i<n; i++){
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }
    int j = 0;
    for(int i=minVal; i<=maxVal; i++){
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }
    }
}
int main(){
    int arr[6] = {5, 1, 4, 2, 8, 0};
    cout << "Before sorting: ";
    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";

        countingsort(arr, 6);
    cout<<endl;
    cout << "After sorting: ";
    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    }
}