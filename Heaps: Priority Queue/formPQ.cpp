#include<iostream>
#include<queue>
using  namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(5);
    pq.push(10);
    pq.push(9);
    pq.push(7);
    pq.push(3);
    pq.push(2);

    while(!pq.empty()){
        cout << " top : " << pq.top() << endl;
        pq.pop();
    }
    return 0;

}