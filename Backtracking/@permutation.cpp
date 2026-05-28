#include<iostream>
#include<vector>
using namespace std;

void getPerm(vector<int> &vec, int idx, vector<vector<int>> &ans) {
    if (idx == vec.size()) {  
        ans.push_back(vec);   
        return;               
    }

    for (int i = idx; i < vec.size(); i++) { 
        swap(vec[idx], vec[i]);
        getPerm(vec, idx + 1, ans);
        swap(vec[idx], vec[i]); // backtrack
    }
}

vector<vector<int>> permutations(vector<int> &vec, int size) {
    vector<vector<int>> ans;
    getPerm(vec, 0, ans);
    return ans; 
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = permutations(nums, nums.size());
    
    for (auto &p : res) {
        for (int x : p) cout << x << " ";
        cout << endl;
    }
}
