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

    printforward(head); 
    return 0;
}
