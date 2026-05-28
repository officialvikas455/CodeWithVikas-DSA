#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx]== -1){
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
        currNode->left = buildTree(nodes);
        currNode-> right = buildTree(nodes);
    return currNode;
}
// preorder Traversal

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// Inoreder Traversal
void inorder(Node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}
//Post Order Traversal
void postorder(Node*root){
    if(root== NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// Level Order Traversal
void levelOrder(Node* root){
    if(root==NULL){
        return;
    }    
    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty()){
        Node* curr  = Q.front();
        Q.pop();
        cout << curr->data <<" ";
        if(curr->left != NULL){
            Q.push(curr->left);
        }
        if(curr->right != NULL){
            Q.push(curr-> right);
        }
    }
    cout << endl;
}
// calculate height of the tree

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currHt = max(leftHt, rightHt) + 1;
    return currHt;
}
// calculate nodes of the tree
int Count(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftCount = Count(root->left);
    int rightCount = Count(root->right);

    return leftCount + rightCount + 1;
}
// calculate sum of the nodes

int Sum(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum = Sum(root->left);
    int rightSum = Sum(root->right);

    int currSum =leftSum + rightSum + root->data;
    cout << " Sum = " << currSum << endl;
 
    return currSum;
}
// Appoarch 1 with Time Complexity = o(n^2).............
int diam1(Node* root){
    if(root == NULL){
        return 0;
    }
    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}   
// Approach @2 with time Complexity 0(n)...
pair<int, int> diam2(Node* root){
    if(root==NULL){
        return make_pair(0,0);
    }
    pair<int, int> leftInfo = diam2(root->left);
    pair<int, int> rightInfo = diam2(root->right);

    int currDiam = (leftInfo.second + rightInfo.second) + 1;    
    int finalDiam = max(currDiam,max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second);

    return make_pair(finalDiam,finalHt);
}
// Find Subtree In a Root

bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }else if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->data != root2->data){
        return false;


    }
    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    }else if(root == NULL || subRoot == NULL){
        return false;
    }
    if(root->data == subRoot->data){
        if(isIdentical(root, subRoot)){
            return true;
        }
    }
    int isLeftSubtree = isSubtree(root->left, subRoot);
    if(!isLeftSubtree){
        return isSubtree(root->right, subRoot);
    }
    return true;

}
/// Top view of a Tree

void topView(Node* root) {
    if(root == NULL) return;
    
    queue<pair<Node*, int>> Q;  // (node, HD)
    map<int, int> m;            // (HD, node->data)
    Q.push(make_pair(root, 0));
    
    while(!Q.empty()) {
        pair<Node*, int> curr = Q.front();
        Q.pop();
        
        Node* currNode = curr.first;
        int currHD = curr.second;
        
        // Only insert if this horizontal distance is not already present
        if(m.find(currHD) == m.end()) {
            m[currHD] = currNode->data;
        }
        
        if(currNode->left != NULL) {
            Q.push(make_pair(currNode->left, currHD-1));
        }
        if(currNode->right != NULL) {
            Q.push(make_pair(currNode->right, currHD+1));  // Was using left instead of right
        }
    }
    
    // Print the top view
    for(auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}
void KthHelper(Node* root, int k, int currLevel){
    if(root == NULL){
        return;
    }
    if(currLevel == k){
        cout << root->data<< " ";
    }
    KthHelper(root->left, k, currLevel + 1);
    KthHelper(root->right, k, currLevel + 1);
}

void KthLevel(Node* root, int k){
    KthHelper(root, k, 1);
    cout << endl;
}
// Ques 1 Find the maximum element in Binary tree

int FindMax(Node* root){
    int root_val , left, right , max= INT_MIN;

    if(root!= NULL){
        root_val = root->data;
        left = FindMax(root->left);
        right = FindMax(root->right);

        //Find the largest value among three
        if(left>right){
            max = left;
        }else{
            max = right;
        }
        if(root_val>max) 
        max = root_val;
    }
    return max;
}

// Lowest common ancestor Approach 1

bool rootToNodePath(Node* root, int n, vector<int> & path){
   if(root==NULL){
    return false;
   }
   path.push_back(root->data);
   if(root->data==n){
    return true;
   }
   int isLeft = rootToNodePath(root->left,n, path);
   int isRight = rootToNodePath(root->right,n, path);

   if(isLeft || isRight){
    return true;
   }
   path.pop_back();
   return false;
}
int LCA(Node* root, int n1, int n2){
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;

    for(int i=0, j=0; i<path1.size() && j< path2.size(); i++, j++){
        if(path1[i] != path2[j]){
            return lca;
        }
        lca = path1[i];

    }
    return lca;
}

Node* LCA2(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }
    return (leftLCA == NULL) ? rightLCA : leftLCA;
}
// Min Distance Between Node

int dist(Node* root, int n){
    if(root==NULL){
        return -1;
    }
    if(root->data == n){
        return 0;
    }
    int leftDist = dist(root->left, n);
    int RightDist = dist(root->right, n);

    if(leftDist != -1){
        return leftDist +1;
    }
    if(RightDist != -1){
        return  RightDist + 1;
    }
    return -1;
}
int minDist(Node* root, int n1, int n2){
    Node* lca = LCA2(root, n1, n2);

    int dist1 = dist(lca,n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}

// Kth Ancestor of Node

int KthAncestor(Node* root, int node, int K){
    if(root == NULL){
        return -1;
    }
    if(root->data == node){
        return 0;
    }
    int leftDist = KthAncestor(root->left, node, K);
    int rightDist = KthAncestor(root->right, node, K);

    int validVal = leftDist == -1 ? rightDist : leftDist;
    if(validVal + 1 == K){
        cout << "Kth Ancestor : " << root->data << endl;
    }
    return validVal + 1;
}

// Transform Sum to tree

int trans(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left != NULL){
        root->data += root->left->data;
    }
    if(root->right != NULL){
        root->data += root->right->data;
    }
    int leftOld = trans(root->left);
    int rightOld = trans(root->right);

    int currOld = leftOld + rightOld;
    return currOld;

}


int main(){
   vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
   Node* root = buildTree(nodes);
   //cout <<" root = " << root->data << endl;
   //cout << " This is preorder traversal : ";
   //preorder(root);
   //cout << endl;
   // cout << " This is inorder traversal : ";
  // inorder(root);
   //cout << endl;
  // cout << " This is Postorder traversal : ";
   //postorder(root);
  // cout << endl;
   //levelOrder(root);
  // cout<< endl;

   //cout << "Height = " << height(root)<<endl;
   //cout << "Total Nodes : " << Count(root) <<endl;

    //Node* root2 = new Node(2);
   //  root2->left = new Node(4);
    // root2->right = new Node(6);
    // cout << "Total Nodes : " << Count(root2) <<endl;

    //cout << "Sum = " << Sum(root) << endl;

    //cout << "Diameter : " << diam2(root).first << endl;

   // Node* subRoot = new Node(2);
   // subRoot->left = new Node(4);
   // subRoot->right = new Node(5);

   /// cout << " The subRoot is : " <<  isSubtree(root, subRoot) << //endl;

   //topView(root);

   // kth level of the tree
   //KthLevel(root,3);

  //cout << " The max is = " << FindMax(root) << endl;
  int n1 = 5, n2 =4;

  //cout << " lca = " << LCA2(root,n1, n2);

  int n=4;

//cout << " min distace between Nodes : " << minDist(root,n1, n2) << endl;

 //KthAncestor(root, 6 , 3);

 cout << " the sum transformation is : " << trans(root) << endl;

    return 0;
}
