#include<iostream>
#include<vector>
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

Node* insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    
    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node* getInorderSuccessor(Node* root){
    while(root->left !=NULL){
        root = root->left;
    }
    return root;
}
Node* delNode(Node* root, int val){
    if(root==NULL){
        return NULL;
    } else{
    if(val < root->data){ // left Subtree
      root->left = delNode(root->left,val);
    }else if (val > root->data){
        root->right = delNode(root->right, val);
    }
    if(root->left == NULL  && root->right == NULL){
        delete root;
        return NULL;
    }
    // case2 : 1 child

    if(root->left == NULL || root->right == NULL){
        return root->left==NULL ? root->right : root->left;
    }
    // case3 : 2 child 
    Node* IS = getInorderSuccessor(root->right);
    root->data = IS->data;
    root->right = delNode(root->right, IS->data);
    return root;
  }
  return root;

}
// Print in Range 
void printInRange(Node* root, int start, int end) {
    if(root == NULL) {
        return;
    }
    if(start <= root->data && root->data <= end) {
        printInRange(root->left, start, end);
        cout << root->data << " ";
        printInRange(root->right, start, end);
    }
    else if(root->data > end) {
        printInRange(root->left, start, end);
    }
    else if(root->data < start) {
        printInRange(root->right, start, end);
    }
}

// Node to leaf path helper functions
void printPath(vector<int>& path) {
    for(int val : path) {
        cout << val << " ";
    }
    cout << endl;
}

void pathHelper(Node* root, vector<int>& path) {
    if(root == NULL) {
        return;
    }
    
    // Add current node to path
    path.push_back(root->data);
    
    // If leaf node, print the path
    if(root->left == NULL && root->right == NULL) {
        printPath(path);
    } else {
        // Recurse for left and right subtrees
        pathHelper(root->left, path);
        pathHelper(root->right, path);
    }
    
    // Backtrack: remove current node from path
    path.pop_back();
}

void rootToLeafPath(Node* root) {
    vector<int> path;
    pathHelper(root, path);
}

int main() {
    int arr[6] = {5, 1, 3, 4, 2, 7};
    Node* root = buildBST(arr, 6);
    
   // cout << "All root to leaf paths:" << endl;
  //  rootToleafPath(root);
    
   // cout << "\nNodes in range [2,5]:" << endl;
  //  printInRange(root);
   // cout << endl;
    rootToLeafPath(root);
    return 0;
}