#include<iostream>
#include<vector>
#include<queue>
using namespace std;

      int minCost(vector<int>& arr) {
          priority_queue<int,vector<int>, greater<int>> pq(arr.begin(), arr.end());
          
          int cost= 0;
          
          while(pq.size()>1){
              int min1 = pq.top();
              pq.pop();
              
              int min2 = pq.top();
              pq.pop();
              
              cost += min1 + min2;
              pq.push(min1 + min2);
          }
          cout << "min cost = "<<cost<<endl; 
      }

  int main(){
    vector<int> arr = {4,3,2,6};
    minCost(arr);
    return 0;
  }