#include<bits/stdc++.h>
using namespace std;
/*getters and setters are an important component to achieve encapsulation in which if we want to access the private
properties, we can use the get and set method
*/

class cars{
    //so if we want to access this private property outside the class, we need to use the getter and setter methods
    int wheels;

    public:
    int gears;

    //in order to set the private property, we use setter
    void setWheels(int n){
        wheels=n;
    }

    //getter
    int getWheels(){
        return wheels;
    }

    void display(){
        cout<<"wheels: "<<wheels<<" "<<"gears: "<<gears<<endl;
    }
};


int main(){
    cars c1;
    cars* c2=new cars;

    c2->gears=6;
    c2->setWheels(4);


    c2->display();






    return 0;
}
