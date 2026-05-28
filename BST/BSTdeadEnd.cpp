class Solution {
    public:
      bool dead(Node* root, int lower , int upper){
          if (!root) return false;
  
          // If it's a leaf node
          if (!root->left && !root->right) {
              if (lower + 1 == root->data && root->data == upper - 1) {
                  return true;
              }
              return false;
          }
  
          return dead(root->left, lower, root->data) || dead(root->right, root->data, upper);
      }
  
      bool isDeadEnd(Node *root) {
          return dead(root, 0, INT_MAX);  // fixed function name
      }
  };
  