#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void  solve(vector<int> & A, int B){
    if(B==0){
        return;
    }
    int ans = 0;
    priority_queue<int> p;
    for(int i=0; i<A.size(); i++){
        if(A[i]) p.push(A[i]);
    }
    while(B!=0 && p.size() != 0){
        ans += p.top();
        if(p.top() > 1){
            p.push(p.top() -1);
            p.pop();
            B--;
        }
        cout << " the profit is : " << ans << endl;
}
}
int main(){
    vector<int> A = {6,8,4,7};
    int B=5;
    solve(A,B);
    return 0;

}