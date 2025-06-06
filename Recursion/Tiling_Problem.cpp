#include<iostream>
using namespace std;

int TilingWays(int n){
    if(n==0 || n==1){
        return 1;
    }
    return TilingWays(n-1) + TilingWays(n-2);
}
int main(){
    int n = 10;
    cout<<TilingWays(n)<<endl;
    return 0;
}