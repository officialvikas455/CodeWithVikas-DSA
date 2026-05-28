class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> m;
        
        for(int i=0; i<arr.size(); i++){
            string original = arr[i];
            
            sort(arr[i].begin(), arr[i].end());
            m[arr[i]].push_back(original);
        }
        vector<vector<string>> ans;
        
        for(auto x : m){
            ans.push_back(x.second);
        }
        return ans;
        
    }
};




/// Better time complexity


// User function Template for C++

class Solution {
    public:
      vector<vector<string>> anagrams(vector<string>& arr) {
          unordered_map<string, vector<string>> m;
          vector<vector<string>> ans;
          
          for(auto s : arr){
              vector<int> count(26, 0);
  
              // Count frequency of each character
              for(auto ch : s){
                  count[ch - 'a']++;  // ✅ FIXED: increment the count
              }
  
              // Create a unique key from the frequency array
              string key;
              for(int i = 0; i < 26; i++){
                  key += "#" + to_string(count[i]);  // "#" ensures uniqueness (e.g., "11" vs "1#1")
              }
  
              m[key].push_back(s);
          }
  
          // Prepare the result from the map
          for(auto& x : m){
              ans.push_back(x.second);
          }
  
          return ans;
      }
  };
  