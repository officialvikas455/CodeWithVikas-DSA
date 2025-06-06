#include<iostream>
using namespace std;
int main(){
    float r;
    cout<<"Enter the radius of the circle: ";
    cin>>r;
    float area = 3.14*r*r;
    float circumference = 2*3.14*r;
    cout<<"The area of the circle is: "<<area<<endl;
    cout<<"The circumference of the circle is: "<<circumference<<endl;
}