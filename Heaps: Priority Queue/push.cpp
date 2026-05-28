#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> vec; // CBT
public:

    void push(int val){
        vec.push_back(val);
        int x = vec.size() - 1;
        int parI = (x - 1) / 2;

        while(x > 0 && vec[x] > vec[parI]){
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x - 1)/2;
        }
    }

    void heapify(int i){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int maxIdx = i;

        if(l < vec.size() && vec[l] > vec[maxIdx])
            maxIdx = l;

        if(r < vec.size() && vec[r] > vec[maxIdx])
            maxIdx = r;

        if(maxIdx != i){
            swap(vec[i], vec[maxIdx]);
            heapify(maxIdx);
        }
    }

    void pop(){
        if(vec.size() == 0) return;

        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();
        heapify(0);
    }

    int top(){
        if(vec.empty()) return -1;
        return vec[0];
    }

    bool empty(){
        return vec.size() == 0;
    }
};

int main(){
    Heap heap;

    heap.push(50);
    heap.push(10);
    heap.push(100);
    heap.push(200);

    cout << heap.top() << endl;  // 200

    heap.pop();

    cout << heap.top() << endl;  // 100

    return 0;
}
