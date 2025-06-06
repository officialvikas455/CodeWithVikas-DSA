#include<iostream>
using namespace std;

bool isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;
    
    while (num > 0) {
        int digit = num % 10;
        reversedNum = (reversedNum * 10) + digit;
        num = num / 10;
    }
    
    return originalNum == reversedNum;
}

int main() {
    int n;
    cout << "Enter a number to check if it's palindrome: ";
    cin >> n;
    
    if (isPalindrome(n)) {
        cout << n << " is a palindrome number" << endl;
    } else {
        cout << n << " is not a palindrome number" << endl;
    }
    
    return 0;
}