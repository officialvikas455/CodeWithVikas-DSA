#include<iostream>
using namespace std;
int main(){
    int p , r , t;
    cout<<"Enter the principal amount : ";
    cin>>p;
    cout<<"Enter the  rate of interest : ";
    cin>>r;
    cout<<"Enter the time in years : ";
    cin>>t;
    float SI = (p*r*t)/100;
    cout<<"The simple interst is : "<<SI<<endl;
}