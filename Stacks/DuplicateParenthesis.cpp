#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

bool isDuplicate(string str){
    stack<char> s;
    char ch;  // moved outside loop so it's accessible

    for(int i=0; i<str.size(); i++){
        ch = str[i];

        if(ch == ')'){
            if(!s.empty() && s.top() == '('){
                return true;
            }

            while(!s.empty() && s.top() != '('){
                s.pop();
            }

            if(!s.empty()) s.pop();
        }
        else{
            s.push(ch);
        }
    }
    return false;
}




// Driver code
int main()
{
    // input balanced expression
    string str = "(((a+(b))+(c+d)))";

    if (isDuplicate(str))
        cout << "Duplicate Found ";
    else
        cout << "No Duplicates Found ";

    return 0;
}