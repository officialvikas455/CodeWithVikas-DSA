#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main(){
    int generateParenthesis(vector<string>s){

        for(int i=0; i<s.size(); i++){
            cout << generateParenthesis(s) <<" ";
        }
    
        return 0;
    
    }
}