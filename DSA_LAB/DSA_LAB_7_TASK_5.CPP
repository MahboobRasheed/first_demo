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
void insertatposition(Node** head, int newdata, int position) {
    Node* new_node = new Node();
    new_node->data = newdata;
    new_node->next = nullptr; 
    new_node->prev = nullptr; 

    if (*head == nullptr || position == 1) {
        new_node->next = *head;
        if (*head != nullptr) {
            (*head)->prev = new_node;
        }
        *head = new_node;
        return;
    }

    Node* temp = *head;
    int currentPosition = 1;
    while (temp->next != nullptr && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp->next == nullptr) {
        temp->next = new_node;
        new_node->prev = temp;
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = new_node;
    }

    temp->next = new_node;
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
    insertatend(&head, 30);
    insertatend(&head, 50);

    cout << "Original List: ";
    printforward(head);
    insertatposition(&head, 20, 2);
    cout << "After inserting 20 at position : ";
    printforward(head);
    insertatposition(&head, 5, 1);
    cout << "After inserting 5 at position : ";
    printforward(head);
    insertatposition(&head, 40, 5);
    cout << "After inserting 40 at position : ";
    printforward(head);

    return 0;
}
