#include<iostream>
using namespace std;

bool ispalindrome(char str[], int n){
    int st=0 , end = n-1;

    while(st<end){
        if(str[st++]!= str[end--]){          // we written this in other way 
            cout<<"not a valid palindrome\n";
            return false;
        }
    }

    cout<<"valid palindrome\n";

    return true;
}

int main(){
    char str[] = "Racket";
    ispalindrome(str, strlen(str));
}