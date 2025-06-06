#include<iostream>
using namespace std;
int main(){
    int n;
    int fact = 1;
    cout<<"Enter a number n : ";
    cin>>n;
    for(i=0; i<=n; i++){
        fact= fact *  i;
    }
    cout<<"Factorial of "<<n<<" is : "<<fact<<endl;
}