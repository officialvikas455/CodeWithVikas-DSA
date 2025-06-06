#include<iostream>
using namespace std;

int digitsString(string str,int idx = 0, int n){
    if(idx % 2 == 0){
        return digitsString(str, idx+1, n);
        cout<< str[idx]<< " ";
        cout << " String at Odd position : " << " ";
    }
    else{
        if(idx == n){
            return 0;
        }
        cout << str[idx] << " ";
        cout << " String at Even position : " << " ";
        return digitsString(str, idx+1, n);
    }
}

int main(){
    string str = "123456789";
    int n = str.size();
    digitsString(str, 0, n);
    cout << endl;
    return 0;
}