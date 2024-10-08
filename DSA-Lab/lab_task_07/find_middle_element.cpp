#include <iostream>
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

Node* findMiddle(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    printforward(head);

    Node* middle = findMiddle(head);
    if (middle != nullptr) {
        cout << "The middle element is: " << middle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
