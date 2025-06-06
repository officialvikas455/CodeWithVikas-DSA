#include<iostream>
using namespace std;

class Car{
    string name;
    string color;


public:
    Car(string nameValue, string colorValue){
        cout<<"Constructor called! object being created..\n"<<endl;
        name = nameValue;
        color = colorValue;

    }

    void start(){
        cout<<"Car started!"<<endl;
    }
    void stop(){
        cout<<"Car stopped!"<<endl;
    }
    // getter 

    string getName(){
        return name;
    }
    string getColor(){
        return color;
    }
};

int main(){
    Car c1("BMW", "Black");
    cout<<"car name is : "<<c1.getName()<<endl;
    cout<<"car color is : "<<c1.getColor()<<endl;
}