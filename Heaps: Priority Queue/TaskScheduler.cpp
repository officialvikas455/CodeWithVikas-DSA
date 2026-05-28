#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void TaskSchedular(vector<char> &tasks, int n){
    priority_queue<char> pq(tasks.begin(), tasks.end());

    for(int i=0;i<=tasks.size(); i++){
        if(tasks[i]) pq.push(tasks[i]);

    }
    if(tasks[0] == tasks[1]){
        return tasks[0] - tasks[1];
    }
}

int main(){
    vector<char> tasks = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V', 'W', 'X','Y','Z'};
    TaskSchedular(tasks,K);
}