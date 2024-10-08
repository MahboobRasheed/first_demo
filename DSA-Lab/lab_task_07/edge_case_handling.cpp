#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

void insertatend(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertatposition(Node** head, int data, int position) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (*head == nullptr && position == 1) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int currentPosition = 1;

    while (temp != nullptr && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr) {
        cout << "Position greater than the length of the list. Inserting at the end." << endl;
        insertatend(head, data);
        return;
    }

    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteatbeginning(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    Node* temp = *head;
    *head = temp->next;
    if (*head != nullptr) {
        (*head)->prev = nullptr;
    }
    delete temp;
}

void deleteAllNodes(Node** head) {
    while (*head != nullptr) {
        deleteatbeginning(head);
    }
    cout << "All nodes deleted." << endl;
}

void traverseForward(Node* head) {
    Node* temp = head;
    cout << "Forward Traversal: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    cout << "Test Case 1: Deleting from an empty list" << endl;
    deleteatbeginning(&head);
    cout << endl;

    insertatend(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);

    traverseForward(head);

    cout << "Test Case 2: Inserting at a position greater than the length of the list" << endl;
    insertatposition(&head, 40, 5);
    traverseForward(head);
    cout << endl;

    cout << "Test Case 3: Deleting all nodes one by one" << endl;
    deleteAllNodes(&head);
    traverseForward(head);
    deleteatbeginning(&head);

    return 0;
}
