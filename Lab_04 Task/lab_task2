#include<iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;        // Data to store
    Node* next;      // Pointer to the next node
};

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();  // Allocate memory for a new node
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;  // If the list is empty, make the new node the head
        return;
    }

    Node* last = *head;  // Traverse to the end of the list
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;  // Insert the new node at the end
}

// Function to reverse the linked list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move prev and current one step forward
        current = next;
    }
    *head = prev;  // Update the head to the new first node
}

// Function to print the linked list
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

    // Create a linked list with user input
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(&head, value);
    }

    // Print the original linked list
    cout << "Original linked list: ";
    printList(head);

    // Reverse the linked list
    reverseList(&head);

    // Print the reversed linked list
    cout << "Reversed linked list: ";
    printList(head);

    return 0;
}
