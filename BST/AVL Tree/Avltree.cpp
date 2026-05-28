#include<iostream>
using namespace std;

class Node{
    public:
    int data, height;
    Node *left, *right;

    Node(int val){
        data = val;
        height = 1;
        left = right = NULL;
    }
};
int getheight(Node* root){
    if(!root)
    return 0;

    return root->height;
}
int getBalance(Node* root){
    return getheight(root->left)- getheight(root->right);

}
// Right Rotation
Node* rightRotation(Node* root){
    Node* child = root->left;
    Node* childRight = root->right;

    child->left = root;
    root->left = childRight;

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;

}
// Left Rotation
Node* leftRotation(Node* root){
    Node* child = root->right;
    Node* childLeft= root->left;
    
    child->left = root;
    root->right = childLeft;

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;

    
}

Node* insert(Node* root,int key){
    //Doest exists
    if(!root){
        return new Node(key);
    }
    // If exists
    if(key < root->data){ // left side attached
     root->left = insert(root->left, key);
    }
    else if(key> root->data){
        root->right = insert(root->right, key);
    } else {
        return root; // duplicate not allowed
    }
    // height upadate 

    root->height = 1 +  max(getheight(root->left) + getheight(root->right));

    //Balanced check
    int balance = getBalance(root);
    // left left case
    if(balance > 1 && key< root->left->data){
     return rightRotation(root);
    }

    // Right Right case
    if(balance < -1 && root->right->data < key){
    return leftRotation(root);
    }

    // Left Right case
    else if(balance >1 && key>root->left->data){
     root->left = leftRotation(root->left);
     return rightRotation(root);
    }

    //Right Left case
    else if(balance <-1 && key<root->left->data){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }


    // No balancing
    else {
        return root;
    }


}

int main(){
    Node* root = NULL;
    // duplicate element not allowed
    
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,50);
    root = insert(root,70);
    root = insert(root,5);
    root = insert(root,100);
    root = insert(root,95);


}