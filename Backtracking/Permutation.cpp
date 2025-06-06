#include<iostream>
#include<string>
#include<vector>
using namespace std;
void  permutation(string str, string ans){
    int n = str.size();
    if(n==0){
        cout<<ans<<"\n";
        return;
    }
    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        string nextstr = str.substr(0,i) + str.substr(i+1, n-i-1);

        permutation(nextstr, ans + ch);
    }

}
int main(){
    string str = "abc";
    string ans = "";
    permutation(str, ans);
    return 0;
}

