#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    int reg_no;
    string st_name;
    float cgpa;

public:
    Student(){
     reg_no = 0; 
     st_name = "";
      cgpa = 0.0;
       }
    void input() {
        cout << "Enter registration number: ";
        cin >> reg_no;
        cin.ignore(); 

        cout << "Enter student name: ";
        getline(cin, st_name);

        cout << "Enter CGPA: ";
        cin >> cgpa;
    }
    void output() {
        cout << "Registration Number: " << reg_no << endl;
        cout << "Student Name: " << st_name << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};
class Stack {
private:
    Student* arr; 
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new Student[capacity];
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(Student s) {
        if (top == capacity - 1) {
            cout << "Stack overflow. Can not push more students" << endl;
        } else {
            arr[++top] = s;
            cout << "Student pushed onto the stack" << endl;
        }
    }
    void pop() {
        if (top == -1) {
            cout << "Stack underflow. No students to pop" << endl;
        } else {
            cout << "Popped Student Details" << endl;
            arr[top--].output();
        }
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size); 

    int choice;
    do {
        cout << "\n1. Push Student\n2. Pop Student\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Student s;
            s.input();
            stack.push(s);
            break;
        }
        case 2:
            stack.pop();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
