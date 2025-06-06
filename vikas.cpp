#include<iostream>
using namespace std;
int main(){
   int sci;
   int math;
   int eng;
   cout<<"Enter sci marks : ";
   cin>>sci;
   cout<<"Enter math marks : ";
    cin>>math;
    cout<<"Enter eng marks : ";
    cin>>eng;

    int avg = (sci + math +eng)/3;
    cout<<"Average is : "<<avg<<endl;


    return 0;
}