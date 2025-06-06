#include<iostream>
using namespace std;
int kandans(int arr[],int n){
    int currSum = 0;
    int maxSum = arr[0];
    for(int i=0; i<n; i++){
        currSum += arr[i];
        if(currSum > maxSum){
            currSum = maxSum;

        }
        else(currSum < 0){
            currSum = 0
    }
    return maxSum;

}
int main(){
    int arr[6] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSubarray = kandans(arr,n);
    cout<<"The Maximum subarray sum :"<<maxSubarray<<endl;
    return 0;

    
}