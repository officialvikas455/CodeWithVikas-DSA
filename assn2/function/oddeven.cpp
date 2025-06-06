#include<iostream>
using namespace std;
bool isEven(int n){
    if(n%2==0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    isEven(5);
    cout<<"number is "<<isEven(8)<<endl;
    return 0;

}