#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

 class Queue{
    int *arr;
    int front , rear, size;

    public: 
      // contructor
        Queue(int n){
            arr = new int[n];
            front = rear = -1;
            size = n;
        }

        // If queue is empty or not 
        bool Isempty(){
            return front == -1;
        }
          // queue is full or not
        bool isFull(){
            return rear == size -1;

        }
        // pushing the value
        void push(int x){
            if(Isempty()){
                cout << " pushed " << x << " into the queue\n";
                front = rear = 0;
                arr[0] = x;
            }
            // is Full
            if(isFull()){
                cout << " Queue Overflow\n";
                return;
            }
            else{
                //insert
                rear = rear+1;
                arr[rear] = x;

            }

        }

        // pop Element

        void pop(){
            if(Isempty()){
                cout << " Queue underflow\n";
                return;
            }
            if(front == rear){
                cout << " Popped " << arr[front] << " into the queue\n ";
                front = rear = -1;
            }else{
                cout << " Popped " << arr[front] << " into the queue\n ";
                front = front + 1;
            }
        }

     // start mein konsa element rakha hai

     int start(){
        if(Isempty()){
            cout << "queue is empty\n";
            return -1;

        }else{
            return arr[front];
        }
     }

 };

int main(){
    Queue queue(5);
    queue.push(511);
    queue.push(53);
    queue.pop();
    queue.pop();
    queue.pop();


    cout << queue.start() << endl;



    return 0;


}
