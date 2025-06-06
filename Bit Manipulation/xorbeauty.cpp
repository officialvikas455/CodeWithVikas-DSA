#include<iostream>
using namespace std;
void xorBeauty(int arr[], int n){
   int  ans =0;
   for(int i=0; i< n; i++){
    for(int j=0; j< n; j++ ){
        for(int k =0; k<n; k++){
            ans = (arr[i] | arr[j]) & arr[k];
        }
    }
   }
    cout << ans << endl;
}
int main(){§
    int arr[10] = {15,45,20,2,34,35,5,44,32,30};

    xorBeauty(arr, 9);
    return 0;
}