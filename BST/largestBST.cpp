/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    public:
      class Box{
          public:
          bool BST;
          int size;
          int min, max;
          Box(int data){
              BST = 1;
              size = 1;
              min = data;
              max = data;
              
          }
          
      };
      
      Box *find(Node* root, int &Totalsize){
          if(!root->left && !root->right){
              Totalsize = max(Totalsize, 1);
              return new Box(root->data);
          }
          else if(!root->left && root->right){
              Box *head = find(root->right , Totalsize);
              if(head->BST && head->min > root->data){
                  head->size++;
                  head->min = root->data;
                  Totalsize = max(Totalsize,head->size);
                  return head;
              }
              else {
                  head->BST = 0;
                  return head;
              }
          }
          else if(root->left && !root->right){
              Box *head = find(root->left, Totalsize);
              if(head->BST && head->max < root->data){
                  head->size++;
                  head->max = root->data;
                  Totalsize = max(Totalsize, head->size);
                  return head;
              }
              else {
                  head->BST = 0;
                  return head;
              }
          }
          // both side exists
          else{
              Box* lefthead = find(root->left, Totalsize);
              Box* righthead = find(root->right, Totalsize);
              
              if(lefthead->BST && righthead->BST &&lefthead->max < root->data && righthead->min > root->data){
                  Box *head = new Box(root->data);
                  head->size += lefthead->size + righthead->size;
                  head->min = lefthead->min;
                  head->max = righthead->max;
                  Totalsize = max(Totalsize, head->size);
                  return head;
              }
              else{
                  lefthead->BST = 0;
                  return lefthead;
              }
          }
      }
      int largestBst(Node *root) {
          int Totalsize = 0;
          find(root, Totalsize);
          return Totalsize;
          // Your code here
          
      }
  };