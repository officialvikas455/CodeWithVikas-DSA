#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

void Union(vector<int> arr1, vector<int>arr2){
    unordered_set<int> s;

    for(int el: arr1){
        s.insert(el);
    }
    for(int el: arr2){
        s.insert(el);
    }
    for(int el: s){
       cout << el << " ,";
    }
    cout << endl;
}

void validIntersection(vector<int> arr1, vector<int> arr2){
    unordered_set<int> s;

    for(int el : arr1){
        s.insert(el);
    }
    for(int el : arr2){
        if(s.find(el) != s.end()){
            cout << el << ",";
            s.erase(el);
        }
    }
    cout << endl;
}


int main(){
    vector<int> arr1={7,3,9};
    vector<int> arr2 ={6,3,9,2,3,4};

    cout<<" union : ";

    Union(arr1, arr2);

    cout << "Intersection";
    validIntersection(arr1, arr2);
    return 0;
}