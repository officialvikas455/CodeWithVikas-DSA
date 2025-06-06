// Function Overloading....
// Function overloading is a compile time polymorphism

#include<iostream>
#include<string>

using namespace std;

class Print{
    public:

    void show(int x){
        cout<<"integer:"<<x<<endl;

    }
    void show(string str){
        cout<<"String :"<<str<<endl;

    }
}; 

/// operator overloading...
// operator overloading is a compile time polymorphism
class Complex{
    int real;
    int img;

    public:
    Complex(int r, int i){
        real = r;
        img = i;
    }
    void show(){
        cout<<real<<"+"<<img<<"i"<<endl;
    }

    Complex operator + (Complex &c2){
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;
        Complex res(resReal, resImg);
       return res;
    }
};

    int main(){
        //Print obj;
        //obj.show(10);
        //obj.show("Hello");

    Complex c1(10, 20);
    Complex c2(30, 40);

    c1.show();
    c2.show();
    Complex c3 = c1 + c2;
        return 0;
    }
    
