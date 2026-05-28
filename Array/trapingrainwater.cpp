#include<iostream>
#include<climits>
using namespace std;

void trap(int *heights, int n){
    int leftMax[20000], rightMax[2000];
    leftMax[0] = heights[0]; 
    rightMax[0] = heights[n-1];
    for(int i = n-1; i >= 0; i--){
        rightMax[i] = max(rightMax[i+1], heights[i]);
    }
    cout << rightMax[0] << ","; 
    cout << leftMax[0] << ",";
    
    for(int i = 1; i < n; i++){  
        leftMax[i] = max(leftMax[i-1], heights[i]);
        cout << leftMax[i] << ",";
    }
}

int main(){
    int heights[7] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(heights)/sizeof(int);
    trap(heights, n);
    return 0;
}