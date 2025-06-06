#include<iostream>
using namespace std;

int allOccurences(int arr[6], int key, int n, int i){
    if(i == n){
        return 0;
    }
    if(arr[i]== key){
        cout<< i << " ";
    }

    return allOccurences(arr, key, i+1, n );
}
int main(){
    int arr[6] = {1, 2, 3, 4, 5, 6,};
    int key = 3;
    int n = 6;
    allOccurences(arr, key, n, 0);
    cout << endl;
    return 0;
}