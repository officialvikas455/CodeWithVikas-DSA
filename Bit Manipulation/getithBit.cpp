#include<iostream>
using namespace std;


int getithBit(int num, int i){
    int bitmask = 1 << i;
    if(num & bitmask==0){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    cout << getithBit(5, 2) << endl; // 1
    cout << getithBit(6, 2) << endl; // 0
    cout << getithBit(5, 0) << endl; // 1
    cout << getithBit(10, 3) << endl; // 1
    cout << getithBit(10, 2) << endl; // 0
    cout << getithBit(10, 1) << endl; // 1
    cout << getithBit(10, 0) << endl; // 0
}