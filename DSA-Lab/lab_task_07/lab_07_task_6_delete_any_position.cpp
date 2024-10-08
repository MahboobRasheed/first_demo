#include<iostream>
using namespace std;

class Node {
public:  
    int data;
    Node* next;
    Node* prev;
};

void insertatend(Node** head, int newdata) {
    Node* new_node = new Node();
    new_node->data = newdata;
    new_node->next = nullptr; 
    new_node->prev = nullptr; 

    if (*head == nullptr) {
        *head = new_node;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;  
}

void deleteatposition(Node** head, int position) {
    if (*head == nullptr) return;

    Node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = nullptr;
        }
        delete temp;
        return;
    }

    int currentPosition = 1;
    while (temp != nullptr && currentPosition < position) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr) return;

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

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
    insertatend(&head, 40);
    insertatend(&head, 50);

    cout << "Original List: ";
    printforward(head);

    deleteatposition(&head, 2);
    cout << "After deleting node at position 2: ";
    printforward(head);

    deleteatposition(&head, 1);
    cout << "After deleting node at position 1: ";
    printforward(head);

    deleteatposition(&head, 3);
    cout << "After deleting node at position 3: ";
    printforward(head);

    return 0;
}
