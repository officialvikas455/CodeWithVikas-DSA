#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int> &q) {
    stack<int> s;
    
    // Push all elements from queue to stack
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    
    // Push all elements back from stack to queue
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    queue<int> q;
    
    // Push elements 1 to 4
    for(int i = 1; i <= 4; i++) {
        q.push(i);
    }
    
/    cout << "Original queue: ";
    queue<int> temp = q;
    while(!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    
    reverse(q);
    
    cout << "Reversed queue: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    return 0;
}