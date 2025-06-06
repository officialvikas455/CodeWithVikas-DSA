#include<iostream>
using namespace std;
int fact(int n){
    int fact=1;
    for(int i=1; i<=n; i++){
        fact = fact * i;
    }
    cout<< "The factorial of " << n << " is = " << fact << endl;
    return fact;
}
int main(){
    fact(5);
    fact(7);
    fact(9);
    fact(11);
}