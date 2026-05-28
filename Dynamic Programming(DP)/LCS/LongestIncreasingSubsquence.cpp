#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

int LIS(vector<int> arr1){
    unordered_set<int> s(arr1.begin(), arr1.end()); // unique
    vector<int> arr2(s.begin(), s.end());
    sort(arr2.begin(), arr2.end()); // acending sorted order

    // LCS -> LIS

    int n = arr1.size();
    int m = arr2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(arr1[i-1] == arr2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];

}


int main(){
    vector<int> arr = {50,3,10,7,40,80};
    cout << LIS(arr) << endl;
    return 0;
}