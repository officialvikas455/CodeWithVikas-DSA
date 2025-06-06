#include<iostream>
using namespace std;
void printsubarrays(int *arr, int n){
    for(int start=0; start<n; start++){
        for(int end= start; end<n; end++){
            cout<<"("<<start<<","<<end<<") ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n=10;
    printsubarrays(arr, n);
    return 0;
}