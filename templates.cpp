#include<bits/stdc++.h>
using namespace std;

/*
Suppose we want to create a class in which the signature would be completely same and we just 
want to change the data type of the class data members.
In that case we can create a temporary variable that can change the data type according to our requirement
*/ 

template<typename T, typename V>
class Pair{
    T x;
    V y;

    public:

    void setX(T x){
        this->x=x;
    }
    void setY(V y){
        this->y=y;
    }

    T getX(){
        return x;
    }
    V getY(){
        return y;
    }

    void dispaly(){
        cout<<"x: "<<x<<endl;
        cout<<"y: "<<y<<endl;
    }
};

int main(){
    Pair<int,double> p1;
    p1.setX(5);
    p1.setY(6.56);

    p1.dispaly();


    return 0;
}