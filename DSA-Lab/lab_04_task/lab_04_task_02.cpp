#include<iostream>
using namespace std;
struct Node {
    int data;        
    Node* next;     
};
void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next; 
        delete temp;        
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Value not found in the list" << endl;
        return;
    }
    prev->next = temp->next;
    delete temp; 
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "\n\n****************** Lab 05 Linked List ****************\n\n" << endl;

    int n, value;
    Node* head = NULL;
    cout << "Enter the number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(&head, value);
    }

    cout << "The linked list is: ";
    printList(head);
    cout << "Enter value to delete: ";
    cin >> value;
    deleteNode(&head, value);
    cout << "The linked list after deletion is: ";
    printList(head);

    return 0;
}
