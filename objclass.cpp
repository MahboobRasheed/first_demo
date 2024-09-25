#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    double* cgpaptr;
    Student(string name, double cgpa){
        this->name=name;
        cgpaptr=new double;
        *cgpaptr=cgpa;
    }
    Student(Student &obj){
        this->name=obj.name;
        cgpaptr = new double;
        *cgpaptr=*obj.cgpaptr;
    }
    void displayinfo(){
        cout<<"name of student is"<<name<<endl;
        cout<<"cgpa of the student"<<*cgpaptr<<endl;

    }
};
int main(){
    Student s1("ali",8.9);
    Student s2(s1);
    s1.displayinfo();
    s2.name="mahb";
    *(s2.cgpaptr)=3.2;
    s2.displayinfo();
}