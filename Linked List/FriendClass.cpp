#include<iostream>
using namespace std;

class Car{
private:
    string engineNumber;

public:
    Car(){
        engineNumber = "127hdhd8404";

    }
    //Decalare a friend class as mechanic

    friend class Mechanic;

};

class Mechanic{
    public:
       void checkEngine(Car c){
        cout << "Accessing engine number: " << c.engineNumber << endl;
       }
};

int main(){
    Car myCar;
    Mechanic m;
    m.checkEngine(myCar); // can access the private memeber
    return 0;
}