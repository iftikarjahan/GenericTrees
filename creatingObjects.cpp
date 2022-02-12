#include<bits/stdc++.h>
using namespace std;

class Student{
    //By default these two properties are made as private.So, if we try to access it we will get an error
    int age;

    public:
    string name;
    int rollNo;

    //Defining a member function in a class
    void print(){
        cout<<name<<":"<<rollNo<<endl;
    }
};

/*
During the creation of a variable, we simply write int a=10.
Here we are mentioning the data type of the variable and then the name of the variable
Similarly, during the creation of an object, we simply need to write the data type----here, 
the data type is Student
*/ 

int main(){
    //Creating Objects Statically
    Student s1;
    
    //Creating objects dynamically
    Student *s2=new Student;

    //Accessing the properties of the class
    s1.name="Jesus";
    s1.rollNo=135;

    s2->name="Samuel";
    s2->rollNo=109;

    //Calling Function for the objects
    s1.print();
    s2->print();



    return 0;
}