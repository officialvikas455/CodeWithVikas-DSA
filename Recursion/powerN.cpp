#include<iostream>
using namespace std;

int pow(int x , int n){
    if(n==0){
        return 1;
    }
    int halfpow = pow(x, n/2);
    int halfpowSq = halfpow * halfpow;
    if(n%2 !=0){
        return  x * halfpowSq;
    }
    else{
        return halfpowSq;
    }
}
int main(){
    cout<<pow(2, 200)<<endl;
    return 0;
}