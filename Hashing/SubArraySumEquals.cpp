#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;

int subArrayCountWithK(vector<int> arr, int K){
    unordered_map<int, int> m; // sum, count
    int sum =0;
    int ans =0;

    for(int j=0; j<arr.size(); j++){
        sum += arr[j];
        if(m.count(sum -K)){
            ans += m[sum-K];
        }
        if(m.count(sum)){
            m[sum]++;
        }else{
            m[sum] = 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {10,2,-2,-20,10};
    int K = -10;
    cout << " Sub Array Sum Equals :->" << subArrayCountWithK(arr, K) << endl;
    return 0;
}