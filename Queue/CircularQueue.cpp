#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int capacity;
    int currSize;
    int f,r;
public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = r = -1;
    }

    void push(int data) {
        if(currSize == capacity) {
            cout << "Queue is Full\n";
            return;
        }
        // Set front pointer when adding first element
        if(f == -1) {
            f = 0;
        }
        r = (r + 1) % capacity;
        arr[r] = data;
        currSize++;
    }

    void pop() {
        if(empty()) {
            cout << "Queue is Empty\n";
            return;
        }
        f = (f + 1) % capacity;
        currSize--;
        // Reset pointers when queue becomes empty
        if(currSize == 0) {
            f = r = -1;
        }
    }

    int front() {
        if(empty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return currSize == 0;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); // This will print "Queue is Full"

    cout << q.front() << endl; // Will print 1
    q.pop();


    return 0;
}