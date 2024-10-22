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
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;
    }
    *head = prev;  
}
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int n, value;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(&head, value);
    }
    cout << "Original linked list: ";
    printList(head);
    reverseList(&head);
    cout << "Reversed linked list: ";
    printList(head);

    return 0;
}
