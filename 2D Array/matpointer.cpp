#include<iostream>
using namespace std;

void func(int mat[][4], int n , int m){
    cout<< "0th row of the matrix" << mat << endl;
    cout<< "1st row of the matrix" << mat + 1 << endl;
    cout<< "2nd row of the matrix" << mat + 2 << endl;
    cout<< "3rd row of the matrix" << mat + 3 << endl;
}

int main(){
    int mat[4][4] = { {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16} };
    int n = 4;
    int m = 4;
    func(mat,n,m);
    return 0;

}
