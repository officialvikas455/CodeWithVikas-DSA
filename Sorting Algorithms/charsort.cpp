#include<iostream>
using namespace std;

int print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}
int charsort(char arr[], int n){
    for(int i=1; i<n; i++){
        char curr = arr[i];
        int prev = i-1;

        while(prev<=0 && arr[prev]<curr){
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
    print(arr, n);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           har arr[6] = {'e', 'a', 'd', 'b', 'c', 'f'};
    cout << "Before sorting: ";
    charsort(arr, 6);

    cout << "After sorting: ";
    return 0;
}