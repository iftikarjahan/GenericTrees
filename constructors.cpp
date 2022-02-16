/*
In order to initialise the data members of a class, we use constructors.
These are of two types
->Default Constructor-If this is not declared, then the inbuilt default constructor is called that initialises the data 
members with some garbage values
If we declare the default con structor ourself, then the inbuilt constructor is no longer applicable
->Praameterised Constructor
*/

#include<bits/stdc++.h>
using namespace std;

class cars{
    public:
    int wheelNo;
    int speed;

    /*
    Rules For creating constructor
    ->same name as that of the class
    ->no return type
    */ 


    //Default Constructor
    cars(){
        wheelNo=4;
        speed=200;
    }

    //Parameterised Constructor using this keyword
    //this keyword is basically a pointer that points towards the memory location of the object
    cars(int wheelNo, int speed){
        this->wheelNo=wheelNo;
        this->speed=speed;
    }

    void display(){
        cout<<"Speed: "<<speed<<endl;
        cout<<"NoOfWheels: "<<wheelNo<<endl;
    }
};

int main(){

    //Creating an object using default constructor
    cars* c1=new cars;

    //Creating an object using parameterised constructor
    cars* c2=new cars(6,300);

    c1->display();
    c2->display();
    return 0;
}