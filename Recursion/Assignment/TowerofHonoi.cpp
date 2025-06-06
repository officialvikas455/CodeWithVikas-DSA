#include<iostream>
using namespace std;

void TOH(int n, int A, int B, int C){
    if(n == 0){
        return;
    }
    TOH(n-1, A, C, B);
    cout << "Move disk " << n << " from rod " << A << " to rod " << C << endl;
    TOH(n-1, B, A, C);

    return TOH(n-1, A, B, C);
}
int main(){
    int n = 3;
    
    return 0;
}