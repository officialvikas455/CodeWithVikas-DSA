#include<iostream>
#include<deque>
using namespace std;

class Queue {
    deque<int> deq;
public:  
    void push(int data) {
        deq.push_back(data);
    }

    void pop() {
        if(empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        deq.pop_front();
    }

    int front() {
        if(empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return deq.front();
    }

    bool empty() {
        return deq.empty();
    }
};

int main() {
    Queue q;

    // Push elements 1 to 5
    for(int i = 1; i <= 5; i++) {
        q.push(i);
    }

    // Print and pop all elements
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    return 0;
}
