#include<iostream>
using namespace std;

void oddorEven(int num){
    if(!(num&1)){
        cout << " is even" << endl;
    }
    else{
        cout <<" is odd" << endl;       
    }
}

int main(){
    oddorEven(5);
    oddorEven(10);
    oddorEven(0);
}