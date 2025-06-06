#include<iostream>
using namespace std;
int  main(){
    float pencile , eraser , sharpner , scale, cost;
    cout<<"enter the cost of the pencile : ";
    cin>>pencile;
    cout<<"enter the cost of the eraser : ";
    cin>>eraser;
    cout<<"enter the cost of the sharpner : ";
    cin>>sharpner;
    cout<<"enter the cost of the scale : ";
    cin>>scale;
     float totcost = pencile + eraser + sharpner + scale;
    cout<<"the total cost of the items is : "<<totcost<<endl;
    cout<<"The total cost after GST is : "<<totcost + (totcost*0.18)<<endl;
 return 0;
}
