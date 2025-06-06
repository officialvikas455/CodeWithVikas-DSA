#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter three digit number : ";
    cin>>n;
    int num = n;

    int digit1 = n%10;
    num = num/10;

    int digit2 = n%10;
    num = num/10;

    int digit3 = num;

    int cubeSum = digit1*digit1*digit1 + digit2*digit2*digit2 + digit3*digit3*digit3;

    if(cubeSum =n ){
        cout<< "is a armstrong number"<<n<<endl;
    }
    else{
        cout<<" is not a armstron number"<<n<<endl;
    }


}