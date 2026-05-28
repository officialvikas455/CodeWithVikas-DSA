#include <iostream>
#include <vector>
using namespace std;

class segmentTree {
    vector<int> tree;
    int n;

    void buildTree(vector<int> &arr, int st, int end, int node) {
        if (st == end) {
            tree[node] = arr[st]; // store leaf node
            return;
        }
        int mid = st + (end - st) / 2;
        buildTree(arr, st, mid, 2 * node + 1);
        buildTree(arr, mid + 1, end, 2 * node + 2);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int rangeSum(int qi, int qj, int si, int sj, int node) {
        // No overlap
        if (qj < si || qi > sj) return 0;

        // Complete overlap
        if (qi <= si && sj <= qj) return tree[node];

        // Partial overlap
        int mid = si + (sj - si) / 2;
        return rangeSum(qi, qj, si, mid, 2 * node + 1) +
               rangeSum(qi, qj, mid + 1, sj, 2 * node + 2);
    }

    void updateUtil(int idx, int newVal, int start, int end, int node){
        if(start==end){
            tree[node] = newVal;
      }
      int mid = start + (end- start)/2;

      if(idx >= start && idx<= end){
        // left
        updateUtil(idx, newVal, start, mid, 2*node+1);
      }else{
        updateUtil(idx, newVal, mid+1, end, 2*node+2);
      }
      tree[node] = tree[2*node+1] + tree[2*node+2];
    }

public:
    segmentTree(vector<int> &arr) {
        this->n = arr.size();
        tree.resize(4 * n, 0);
        buildTree(arr, 0, n - 1, 0);
    }

    void printTree() {
        for (int i = 0; i < tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    int rangeQuery(int qi, int qj) {
        return rangeSum(qi, qj, 0, n - 1, 0);
    }
    int updateQuery(int idx, int val){
        return updateUtil(idx,val,n-1,0);
    }
};

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8};
    segmentTree st(arr);

    st.printTree();

    cout << "Sum of range [2,5] = " << st.rangeQuery(2,5) << endl;
    cout << "Sum of range [0,7] = " << st.rangeQuery(0,7) << endl;

    return 0;
}