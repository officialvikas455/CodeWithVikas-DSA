/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
    public:
      Node* segregate(Node* head) {
          // code here
          Node* curr = head;
          int count0 = 0, count1 = 0, count2 = 0;
          
          // counting 0s, 1s, and 2s
          while (curr) {
              if (curr->data == 0) count0++;
              else if (curr->data == 1) count1++;
              else if (curr->data == 2) count2++;  // ✅ fixed: added 'if' before (curr->data==2)
              curr = curr->next;
          }
          
          // resetting pointer to head
          curr = head;  // ✅ fixed: you must reset curr before rewriting values
          
          // rewriting values in order
          while (count0--) {
              curr->data = 0;
              curr = curr->next;
          }
          while (count1--) {
              curr->data = 1;
              curr = curr->next;
          }
          while (count2--) {
              curr->data = 2;
              curr = curr->next;
          }
          return head;
      }
  };
  