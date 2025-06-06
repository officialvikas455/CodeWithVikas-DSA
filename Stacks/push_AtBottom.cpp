#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

void pushAtBottom(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(temp);
}

string reverseString(string str){   
    string ans;
    stack<char> s;
    for(int i=0; i<str.size(); i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        char top = s.top();
        ans += top;
        s.pop();
    }
    return ans;
}
void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s, temp);
}
void printstack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout<<"\n";
}

void stockSpanProblem(vector<int> stock, vector<int> span){
    stack <int>s;
    s.push(0);
    span[0] = 1;

    for(int i=0; i< stock.size(); i++){
        int currPrice = stock[i];
        while(!s.empty() && currPrice >= stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span[i] = i+1;
        }else{
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }
        s.push(i);
       
    }
    for(int i=0 ; i< span.size(); i++){
        cout << span[i] << " ";

    }
    cout<< endl;

}

void nextGreater(vector<int> arr, vector<int> ans){
    stack<int> s;
    int idx = arr.size()-1;
    ans[idx] = -1;
    s.push(arr[idx]);

    for(idx = idx - 1; idx >= 0; idx--){
        int curr = arr[idx];
        while(!s.empty() && curr >= s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[idx] = -1;
        }else{
            ans[idx] = s.top();
        }
        s.push(curr);
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout<< endl;
}


int main(){
        vector<int> arr = {6, 8, 0, 1, 3};
        vector<int> ans = {0, 0, 0, 0, 0};

        nextGreater(arr, ans);
 
        
        return 0;

}        
