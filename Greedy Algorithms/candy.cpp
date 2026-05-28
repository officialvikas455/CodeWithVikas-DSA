#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // First pass: check left neighbor
        for (int idx = 1; idx < n; idx++) {
            if (ratings[idx] > ratings[idx - 1]) {
                candies[idx] = candies[idx - 1] + 1;
            }
        }

        // Second pass: check right neighbor
        int sum = candies[n - 1];
        for (int idx = n - 2; idx >= 0; idx--) {
            if (ratings[idx] > ratings[idx + 1]) {
                candies[idx] = max(candies[idx], candies[idx + 1] + 1);
            }
            sum += candies[idx];
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {1, 0, 2}; // You can change input here
    cout << "Minimum candies required: " << sol.candy(ratings) << endl;
    return 0;
}
