#include<iostream>
using namespace std;
int main(){
    int n =12345;
    int digSum = 0;
    while(n>0){
        int lastdig = n%10;
        digSum += lastdig;
        n = n/10;
        cout<<"Sum : "<<digSum<<endl;
    }

    return 0;
}