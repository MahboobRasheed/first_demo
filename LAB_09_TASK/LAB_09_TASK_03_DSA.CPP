#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;
    int MAX_SIZE;

public:
    Queue(int size = 5) {  
        front = nullptr;
        rear = nullptr;
        count = 0;
        MAX_SIZE = size;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is overflow can not insert more elements" << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        cout << "Inserted " << val << " into the queue " << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow, no elements to remove " << endl;
            return -1;
        } else {
            Node* temp = front;
            int removedValue = front->data;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            count--;
            return removedValue;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            cout << "Queue elements";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue queue1(5);  
    Queue queue2(5); 
    int option;

    do {
        cout << "\nSelect an operation\n";
        cout << "1. Insert into first queue (enqueue)\n";
        cout << "2. Remove from first queue (dequeue and move to second queue)\n";
        cout << "3. Remove from second queue (dequeue)\n";
        cout << "4. Display both queues\n";
        cout << "5. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1: {
                int val;
                cout << "Enter value to insert into the first queue: ";
                cin >> val;
                queue1.enqueue(val);
                break;
            }

            case 2: {
                int val = queue1.dequeue(); 
                if (val != -1) {
                    queue2.enqueue(val);
                }
                break;
            }

            case 3: {
                int val = queue2.dequeue(); 
                if (val != -1) {
                    cout << "Removed " << val << " from the second queue." << endl;
                }
                break;
            }

            case 4: {
                cout << "First Queue: ";
                queue1.displayQueue();
                cout << "Second Queue: ";
                queue2.displayQueue();
                break;
            }

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid option! Please try again." << endl;
                break;
        }
    } while (option != 5);

    return 0;
}   