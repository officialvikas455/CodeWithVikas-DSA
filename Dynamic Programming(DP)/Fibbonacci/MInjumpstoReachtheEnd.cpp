// c++ program to find the minimum number
// of jumps to reach the end of the array
#include<iostream>
using namespace std;

int minJumpsRecur(int i, vector<int> &arr) {
    
    // Return 0 when last element is reached.
    if (i >= arr.size()-1)
        return 0;

    // Traverse through all the points
    // reachable from arr[i].
    // Recursively, get the minimum number
    // of jumps needed to reach array end from
    // these points.
    int ans = INT_MAX;
    for (int j=i+1; j<=i+arr[i]; j++) {
        int val = minJumpsRecur(j, arr);
        if (val != INT_MAX)
            ans = min(ans, 1+val);
    }

    return ans;
}

// Function to return the minimum number
// of jumps to reach arr[h] from arr[l]
int minJumps(vector<int>& arr) {

    int ans =  minJumpsRecur(0, arr);
    
    // If end cannot be reached.
    if (ans == INT_MAX) 
        return -1;
        
    return ans;
}

int main() {
    vector<int> arr = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    cout << minJumps(arr);
    return 0;
} 