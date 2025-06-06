#include<iostream>
#include<string>
using namespace std;

class Animal{
    public:
    void eat(){
        cout<<"Animal is eating:\n";
    }
    void sleep(){
        cout<<"Animal is sleeping:\n";
    }
    void run(){
        cout<<"Animal is running:\n";
    }
};

class Mammal: public Animal{
    public:
    string bloodType;
    Mammal (){
        bloodType = "Warm Blooded";
    }
    
};

class Dog : public Mammal{
    public :
    void tailwag(){
        cout<<"Dog is wagging its tail:\n";
    }
};



int main(){
    Dog d1;
    d1.eat();
    d1.sleep();
    d1.run();
    d1.tailwag();
    cout<<"Dog is a "<<d1.bloodType<<" animal:\n";
    return 0;

}