#include<iostream>
using namespace std;
void transpose(int mat[][4], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < m; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
}
int main(){
    int mat[4][4] = {{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}};
    int n = 4;
    int m = 4;
    transpose(mat, n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}