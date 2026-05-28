#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Row {
public:
    int idx;
    int count;

    Row(int idx, int count) {
        this->idx = idx;
        this->count = count;
    }

    bool operator <(const Row &obj) const {
        if (this->count == obj.count) {
            return this->idx > obj.idx; // Compare indices if counts are equal
        }
        return this->count > obj.count; // Min-heap based on count
    }
};
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<Row> rows;
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size() && mat[i][j] == 1; j++) {
                count++;
            }
            rows.push_back(Row(i, count)); // Store index and count
        }

        priority_queue<Row> pq(rows.begin(), rows.end());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            if (!pq.empty()) {
                Row weakest = pq.top();
                pq.pop();
                result.push_back(weakest.idx); // Store the index of the weakest row
            }
        }
       return result;
 }  //Return the indices of the k weakest rows

 int main(){
    vector<vector<int>> mat = {{1,0,0,0},
                               {1,1,1,1},
                            {1,0,0,0},
                        {1,0,0,0}};
    int k = 2;
    kWeakestRows(mat,k);
    return 0;                    
 }   
