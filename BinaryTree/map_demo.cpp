#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<int, string> m;
    m[101] = "Rahul";
    m[102] = "Neha";
    cout << m.count(101) << endl;

    for(auto it: m){
        cout << "key = " << it.first << "," << "value = " << it.second << endl;
    }
    return 0; 
}