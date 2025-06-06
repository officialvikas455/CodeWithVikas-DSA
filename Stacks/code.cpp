#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Stacks{
    vector<int> vec;
public:
      void push(int val){
        vec.push_back(val);
      }
      void pop(){
        vec.pop_back();
      }

      T top(){
        int lastIdx = vec.size()-1;
        return vec[lastIdx];  // Added return statement
      }
      bool isEmpty(){
        return vec.size()==0;
      }

};

int main(){
    Stacks<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout<< s.top() << " ";
        s.pop();
    }
    return 0;
}