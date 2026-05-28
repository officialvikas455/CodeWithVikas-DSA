#include<iostream>
#include<deque>
#include<stack>
using namespace std;

class stacks{

    deque<int> deq;

    public: 
    void push(int data){
        deq.push_front(data);
    }
    void pop(){
        deq.pop_front();
    }
    int top(){
        return deq.front();
    }

};

int main(){
    stacks s;
    
        // Push elements 1 to 5
        for(int i = 1; i <= 5; i++) {
            s.push(i);
        }
    
        for(int i = 1; i <= 5; i++) {
            cout << s.top() << " ";
            s.pop();
        }    
        cout << endl;
        
        return 0;
    }
