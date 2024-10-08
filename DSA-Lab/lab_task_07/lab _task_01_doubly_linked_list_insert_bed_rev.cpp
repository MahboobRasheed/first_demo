#include<iostream>
using namespace std;

class Node {
public:  
    int data;
    Node* next;
    Node* prev;
};

void insertatbeginning(Node** head, int newdata) {
    Node* new_node = new Node();
    new_node->data = newdata;
    new_node->next = (*head);
    new_node->prev = nullptr;

    if (*head != nullptr) {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

void reverseList(Node** head) {
    Node* current = *head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        *head = temp->prev;
    }
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

    insertatbeginning(&head, 10);
    insertatbeginning(&head, 20);
    insertatbeginning(&head, 30);

    printforward(head);

    reverseList(&head);

    cout << "Reversed linked list: ";
    printforward(head);

    return 0;
}
