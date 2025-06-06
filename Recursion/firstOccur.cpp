#include<iostream>
using namespace std;
int firstOccur(vector <int> arr, int target, int i){
    if(i == arr.size()){
        return -1;
    }
    if(arr[i] == target){
        return i;
    }
    return firstOccur(arr, target, i+1);
}
int main(){
    vector <int> arr = {1, 2, 3, 3, 3, 3, 3};
    cout << firstOccur(arr, 4 , 0)<<endl;
    return 0;
}