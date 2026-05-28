#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
    
        void solve(vector<string>& result, string current, int openCount, int closeCount, int n){
            if (openCount == n && closeCount == n) {
                result.push_back(current);
                return;
            }
            if(openCount < n){
                solve(result, current + "(", openCount+1, closeCount, n);
    
            }
            if(closeCount < openCount){
                solve(result, current +")", openCount, closeCount+1,n);
            }
        }
         
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            solve(result,"",0,0,n);
            return result;
            
        }        
    };
int main(){
    int n=5;

cout << generateParenthesis(n) << endl;;

            return 0;
 }