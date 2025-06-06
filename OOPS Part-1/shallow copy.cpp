#include<iostream>
#include<string>
using namespace std;
class Car{
    public:
    string name;
    string color;
    int *mileage;
Car (string name, string color){
    this->name = name;
    this->color = color;
    mileage = new int;
    *mileage = 17;
}   
Car (Car &original){
    cout<<"coying to new constructor\n";
    this->name = original.name;
    this->color = original.color;
    this->mileage = new int;
    *(this->mileage) = *(original.mileage);

}

}; 
int main(){
    Car C1("BMW", "Black");
    Car C2(C1); // shallow copy
    cout<<"C1 name: "<<C2.name<<endl;
    cout<<"C1 color: "<<C2.color<<endl;
    cout<<"C1 mileage: "<<*(C2.mileage)<<endl;
    cout<<"C2 name: "<<C2.name<<endl;

return 0;    
    
}   
