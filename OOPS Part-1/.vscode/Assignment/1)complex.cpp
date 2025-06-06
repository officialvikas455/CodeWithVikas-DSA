#include<iostream>
#include<string>
using namespace std;

class Complex{
    int real;
    int img;

    public:
    Complex(int r, int i){
        real = r;
        img = i;
    }
    void show(){
        cout<< real <<"-"<<img<<"i"<<endl;
    }

    Complex operator - (Complex &c2){
        int resReal = this->real - c2.real;
        int resImg = this->img - c2.img;
        Complex res(resReal, resImg);
       return res;
    }
};
int main(){
    Complex c1(10, 20);
    Complex c2(30, 40);

    c1.show();
    c2.show();

    c2 = c2 - c1;

        return 0;
}
