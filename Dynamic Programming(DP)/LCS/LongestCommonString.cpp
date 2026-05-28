#include<iostream>
#include<vector>
#include<string>
using namespace std;
      int longestCommonSubstr(string& s1, string& s2) {
          int n = s1.size();
          int m = s2.size();
          int ans=0;
          
          vector<vector<int>> dp(n+1, vector<int>(m+1,0));
          
          for(int i=1; i<n+1; i++){
              for(int j=1; j<m+1; j++){
                  if(s1[i-1] == s2[j-1]){
                      dp[i][j] = 1 + dp[i-1][j-1];
                      ans = max(ans, dp[i][j]);
                  }else{
                      dp[i][j] = 0;
                  }
              }
          }
          
          for(int i=0; i<n+1; i++){
              for(int j=0; j<m+1; j++){
                  cout << dp[i][j] << " ";
              }
              cout <<endl;
          }
          return ans;
        
          
      }
int main(){
    string s1 ="abcde";
    string s2 = "abgce";

    cout << longestCommonSubstr(s1, s2) << endl;
    return 0;
}