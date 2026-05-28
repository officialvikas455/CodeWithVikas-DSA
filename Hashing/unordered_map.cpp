#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    unordered_map<string,int> m;
    m["china"] = 150;
    m["india"] = 140;
    m["US"] = 160;

    for(pair<string, int> country : m){
        cout << country.first<< "," << country.second <<  endl;
    }
}