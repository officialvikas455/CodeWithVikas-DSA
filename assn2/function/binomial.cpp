#include<iostream>
using namespace std;

int fact(int n){
    int fact=1;
    for(int i=1; i<=n; i++){
        fact = fact * i;
    }
    return fact;
}
int bincoeff(int n, int r){
    int val1 = fact(n);
    int val2 = fact(r);
    int val3 = fact(n-r);
    int binomial = val1/val2*val3;
    return binomial;
}
int main(){
   cout<< "The binomial coefficient of 4 and 2 is = " << bincoeff(4,2) << endl;
}

