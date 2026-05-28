#include<iostream>
#include<climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class Info {
public:
    bool isBST;
    int min;
    int max;
    int size;
    
    Info(bool isBST, int min, int max, int size) {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

static int maxBSTSize = 0;

Info* largestBST(Node* root) {
    if(root == NULL) {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }
    
    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);
    
    Info* currInfo = new Info(false, 0, 0, 0);
    currInfo->size = leftInfo->size + rightInfo->size + 1;
    currInfo->min = min(root->data, min(leftInfo->min, rightInfo->min));
    currInfo->max = max(root->data, max(leftInfo->max, rightInfo->max));
    
    if(leftInfo->isBST && rightInfo->isBST 
       && root->data > leftInfo->max 
       && root->data < rightInfo->min) {
        currInfo->isBST = true;
        maxBSTSize = max(maxBSTSize, currInfo->size);
    }
    
    return currInfo;
}

int main() {
    // Create test tree
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);
    
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    
    // Find largest BST
    maxBSTSize = 0;  // Reset static variable
    Info* result = largestBST(root);
    
    cout << "Size of largest BST in the binary tree: " << maxBSTSize << endl;
    
    return 0;
}