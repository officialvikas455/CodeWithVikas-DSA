#include<iostream>
using namespace std;
void binTodec(int binNum){
    int n = binNum;
    int decNum = 0;
    int pow = 1;
    while(n>0){
        int lastDigit = n%10;
        n = n/10;
        decNum += lastDigit*pow;
        pow = pow*2;

    }
    cout<<decNum<<"\n";
}
int main(){
    int binNum;
    cout<<"Enter a binary number: ";
    cin>>binNum;
    binTodec(binNum);
    return 0;
}