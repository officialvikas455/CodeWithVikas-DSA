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

void pairedSum(Node* root, vector<int, int > & k){
    if(root == NULL){
        return;
    }
    
}