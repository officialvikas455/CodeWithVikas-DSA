#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> keypad = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void helper(string input, int pos, int n, string ans) {
    if(pos == n) {
        cout << ans << endl;
        return;
    }
    
    string current = keypad[input[pos] - '0'];
    for(int i = 0; i < current.length(); i++) {
        helper(input, pos + 1, n, ans + current[i]);
    }
}

void letterCombination(string input) {
    int n = input.size();
    if(n == 0) {
        cout << "No number pressed!" << endl;
        return;
    }
    helper(input, 0, n, "");
}

int main() {
    letterCombination("234");
    return 0;
}
