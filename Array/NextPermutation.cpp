#include<iostream>
#include<vector>
using namespace std;

int  NextPermutation(vector<int> &arr){
    int n = arr.size();
    int idx = -1;

    for(int i=n-2; i>=0; i--){
        if(arr[i] < arr[i+1]){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        reverse(arr.begin(), arr.end());
        return arr[i];
    }
    for(int i=n-1; i>idx; i--){
        if(arr[i] > arr[idx]){
            swap(arr[i], arr[idx]);
            break;
        }
    }
    reverse(arr.begin(), arr.end());
    return arr[i];

}
int main(){
    vector<int> arr = {2,1,5,4,3,0,0};
     NextPermutation(arr) ;
    return 0;
}