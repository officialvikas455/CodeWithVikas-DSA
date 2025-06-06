#include<iostream>
using namespace std;
void maxsubarraysum(int *arr, int n){
    int maxsum= INT_MIN;
    for(int start=0; start<n; start++){
        for(int end= start; end<n; end++){
            int currsum=0;
            for(int i=start; i<=end; i++){
                currsum += arr[i];
            }
            cout<<currsum<<","; 
            maxsum = max(maxsum, currsum);
            
    }
    cout<<endl;
    }
    cout<<"Max subarray sum is: "<<maxsum<<endl;
}
int main(){
    int arr[6] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    maxsubarraysum(arr, n);
    return 0;

}
