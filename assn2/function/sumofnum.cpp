#include<iostream>
using namespace std;
int digSum(int n){
    int res = 0;
    while(n>0){
        res = res + n%10;
        n = n/10;
    }
    return res;
}
int main(){
    digSum(1234);
    cout<<"The sum of digits is = "<<digSum(1234) << endl;
}


