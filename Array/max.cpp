#include<iostream>
using namespace std;
int main(){
    int arr[] = {5 , 10, 15, 20};
    int n = sizeof(arr)/sizeof(int);
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
            cout<<" assigning val "<< max << " to max\n";
        }
    }
    cout<<"The maximum value in the array is: " << max << endl;
    return 0;

}