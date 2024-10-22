#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insertatend(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}
void remove(Node** head, int value) {
    Node* temp = *head;
    Node* prev = nullptr;
    if (temp != nullptr && temp->data == value) {
        *head = temp->next;  
        delete temp;        
        return;
    }
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) return;

    prev->next = temp->next;

    delete temp;  
}
void printforward(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    insertatend(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);

    cout << "Original List: ";
    printforward(head);

    remove(&head, 30);  

    cout << "List after removing : ";
    printforward(head);

    return 0;
}
