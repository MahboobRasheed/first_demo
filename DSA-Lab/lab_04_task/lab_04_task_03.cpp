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
        cout << "Node with value " << key << " deleted successfully." << endl;
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value " << key << " not found in the list." << endl;
        return;
    }

    prev->next = temp->next;  
    delete temp;              
    cout << "Node with value " << key << " deleted successfully." << endl;
}
bool searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return true;  
        }
        current = current->next;
    }
    return false; 
}
void printList(Node* node) {
    if (node == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int value;
    cout << "Enter values for 5 nodes:" << endl;
    for (int i = 0; i <5 ; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(&head, value);
    }
    cout << "The linked list is: ";
    printList(head);
    cout << "Enter value to search: ";
    cin >> value;
    if (searchNode(head, value)) {
        cout << "Value " << value << " found in the list." << endl;
    } else {
        cout << "Value " << value << " not found in the list." << endl;
    }
    cout << "Enter value to delete: ";
    cin >> value;
    deleteNode(&head, value);
    cout << "The linked list after deletion is: ";
    printList(head);

    return 0;
}
