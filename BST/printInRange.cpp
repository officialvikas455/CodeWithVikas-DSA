#include <vector>
#include<iostream>
using namespace std;

class Solution {
private:
    void find(Node* root, vector<int>& ans, int low, int high) {
        if (!root) return;
        
        // If root->data > high, we only need to search left subtree
        if (root->data > high) {
            find(root->left, ans, low, high);
        }
        // If root->data < low, we only need to search right subtree
        else if (root->data < low) {
            find(root->right, ans, low, high);
        }
        // If root->data is in range, process left, root, right
        else {
            find(root->left, ans, low, high);
            ans.push_back(root->data);
            find(root->right, ans, low, high);
        }
    }

public:
    vector<int> printNearNodes(Node* root, int low, int high) {
        vector<int> ans;
        find(root, ans, low, high);
        return ans;
    }
};