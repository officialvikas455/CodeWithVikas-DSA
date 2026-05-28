#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Create a max-heap using a priority queue
        priority_queue<int> pq(stones.begin(), stones.end());

        // Continue until there is one or no stones left
        while (pq.size() > 1) {
            // Get the two heaviest stones
            int x = pq.top(); // The heaviest stone
            pq.pop();
            int y = pq.top(); // The second heaviest stone
            pq.pop();

            // If they are not the same weight, push the difference back into the heap
            if (x != y) {
                pq.push(x - y);
            }
        }

        // If there is a stone left, return its weight; otherwise, return 0
        return pq.empty() ? 0 : pq.top();
    }
};
