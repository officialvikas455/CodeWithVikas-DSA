#include<iostream>
using namespace std;

int prod(int a, int b){
    return a*b;
}

int main(){
    prod(5, 6);
    cout<< "The product of 5 and 6 is: " << prod(5, 6) << endl;
    cout<< "The product of 7 and 8 is: " << prod(7, 8) << endl;
    cout<< "The product of 9 and 10 is: " << prod(9, 10) << endl;
    cout<< "The product of 11 and 12 is: " << prod(11, 12) << endl;
    cout<< "The product of 13 and 14 is: " << prod(13, 14) << endl;
}