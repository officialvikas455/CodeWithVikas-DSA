#include<iostream>
using namespace std;

class Node {
    public:

    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }   
   // ~Node() {
   //     cout<< "Node destructor for data = "<< data << endl;
   //     if(next != NULL){
   //         delete next;
   //         next = NULL;
   //     }
  //  } 
};
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = NULL;
        tail = NULL;

    }

   //~List(){
      //  cout<< "List destructor";
      //  if(head != NULL){
       //     delete head;
        //    head = NULL;
      //  }
   // }
    void push_front(int val){
        Node* newNode = new Node(val);// dynamic

            if(head == NULL){
                head = tail = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;

        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp->data <<" -> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
    void insert(int val, int pos){
        Node* temp = head;
        Node* newNode = new Node(val);
        for(int i=0; i<pos-1; i++){
            if(temp==NULL){
                cout<<"Invalid Position\n";
                return;
            }
            temp = temp->next;
            
        }
        //temp is now at pos-1 i.e. prev/left
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void pop_front(){
        if(head == NULL){
            cout<< "LL is Empty\n";
        }
        Node* temp = head;
        head = head-> next;
        temp-> next = NULL;
        delete temp;
    }
    int searchItr(int key){
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp-> data ==key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    int helper(Node* temp, int key){
        if(temp == NULL){
            return -1;
        }
        if(temp->data == key){  // Fix comparison
            return 0;
        }
        int idx = helper(temp->next, key);
        if(idx == -1){
            return -1;
        }
        return idx + 1;
    }

    int size(){
        int sz = 0;
        Node* temp = head;
        while(temp != NULL){
            sz++;
            temp = temp->next;
        }
        return sz;
    }

    void removeNth(int n){
        Node* prev = head;

        for(int i=1; i<size(); i++){
            prev = prev->next;
        }
        Node* toDel = prev->next;
        cout<<"going to delete:"<<toDel->data<<endl;

        prev->next = prev->next->next;
    }

    void removeCycle() {  // Remove head parameter as we already have it as member
        // detect cycle
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while(fast != NULL && fast->next != NULL) {
            prev = fast;
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                cout << "cycle exists\n";
                break;
            }
        }

        slow = head;
        while(slow != fast) {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = NULL;
    }

    Node* splitAtMid(Node* head){
        Node* slow = head;
        Node* fast= head;
        Node* prev = NULL;
        while( fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev != NULL){
            prev->next = NULL; // split at Middle
        }
        return slow;
    }

    Node* reverse(Node* head) {
        Node *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* zigZagLL(Node* head) {
        // Split the list
        Node* rightHead = splitAtMid(head);
        Node* leftHeadRev = reverse(rightHead);
        
        // Alternate merging
        Node* left = head;
        Node* right = leftHeadRev;
        Node* tail = right;
        
        while(left != NULL && right != NULL) {
            Node* nextLeft = left->next;
            Node* nextRight = right->next;
            
            left->next = right;
            right->next = nextLeft;
            
            tail = right;
            
            left = nextLeft;
            right = nextRight;
        }
        
        if(right != NULL) {
            tail->next = right;
        }
        return head;
    }

};

int main() {
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(0);
    ll.push_back(4);
    ll.push_back(6);
    
    cout << "Original list: ";
    ll.printList();
    ll.head = ll.zigZagLL(ll.head);
    ll.printList();

    return 0;
}
