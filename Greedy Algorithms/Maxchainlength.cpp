#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int , int> p1, pair<int, int> p2){
    return p1.second < p2.second; // ascending order of second element
}

int maxChainLength(vector<pair<int, int>> &pairs){
    int n = pairs.size();

    sort(pairs.begin(), pairs.end(), compare);

    int ans = 1;
    int currEnd = pairs[0].second;

    for(int i = 1; i < n; i++){
        if(pairs[i].first > currEnd){
            ans++;
            currEnd = pairs[i].second;
        }
    }

    cout << "Max Chain Length: " << ans << endl;
    return ans;
}

int main(){
    vector<pair<int, int>> pairs = {
        {5, 24},
        {39, 60},
        {5, 28},
        {27, 40},
        {50, 90}
    };

    maxChainLength(pairs);

    return 0;
}