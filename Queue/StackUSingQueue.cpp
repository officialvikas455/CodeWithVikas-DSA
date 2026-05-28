#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1; 
    queue<int> q2;
public:
   void push(int data){
    while(!empty()){
        q2.push(q1.front()); // push data from q1 -> q2
        q1.pop();           // then pop the whole element who pushed in q2

    }
    q1.push(data);      // push the items

    while(!q2.empty()){       // reverse store q2 -> q1 fronm front because in stacks elements store in reverse order 
        q1.push(q2.front());  
        q2.pop();
    }

   }
   void pop(){
    if(empty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    q1.pop();
   }
   int top(){
    if(empty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return q1.front();

   }
   bool empty(){
   return  q1.empty();

   }


   
};

int main(){
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;

}