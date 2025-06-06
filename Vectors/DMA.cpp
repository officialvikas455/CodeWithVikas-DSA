#include<iostream>
using namespace std;

int main(){
    int *arr = new int(size);
    arr[0] = *(arr+0);
    arr[1] = *(arr+1);
    arr[2] = *(arr+2);
    arr[3] = *(arr+3);
    arr[4] = *(arr+4);

    int x=1;

    for(int i=0; i<size; i++){
        arr[i] = x;

        cout<<arr[i]<<endl;
    }

}