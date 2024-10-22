#include<iostream>
using namespace std;

class Person {
private:
    int per_id;
    string per_name;
    int per_age;

public:
    Person() : per_id(0), per_name(""), per_age(0) {}

    void input() {
        cout << "Enter Person ID: ";
        cin >> per_id;
        cout << "Enter Person Name: ";
        cin >> per_name;
        cout << "Enter Person Age: ";
        cin >> per_age;
    }

    void display() const {
        cout << "Person ID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << endl;
    }
};

class Node {
public:
    Person data;
    Node* next;
    Node(Person p){ 
    data = p;
    next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void addQueue(Person p) {
        Node* newNode = new Node(p);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Person added to the queue successfully!" << endl;
    }

    Person removeQueue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue!" << endl;
            return Person();
        } else {
            Node* temp = front;
            Person removedPerson = front->data;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            return removedPerson;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            Node* temp = front;
            while (temp != nullptr) {
                temp->data.display();
                temp = temp->next;
            }
        }
    }
};

int main() {
    Queue q;
    int option;
    Person p;

    do {
        cout << "\nSelect an operation:\n";
        cout << "1. Add Person to Queue (enqueue)\n";
        cout << "2. Remove Person from Queue (dequeue)\n";
        cout << "3. Display Queue\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
        case 1:
            p.input();
            q.addQueue(p);
            break;

        case 2: {
            Person removedPerson = q.removeQueue();
                cout << "Removed Person: ";
                removedPerson.display();
        
            break;
        }

        case 3:
            cout << "Current Queue:\n";
            q.displayQueue();
            break;

        case 4:
            if (q.isEmpty()) {
                cout << "Queue is empty.\n";
            } else {
                cout << "Queue is not empty.\n";
            }
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option! Please try again.\n";
            break;
        }

    } while (option != 5);

    return 0;
}
