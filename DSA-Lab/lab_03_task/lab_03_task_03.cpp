#include<iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;          // Data to store
    Node* next;        // pointer to next node
};

// Function to insert a node at the end
void insertAtEnd(Node** head, int newData) {
    // Allocate memory for new node
    Node* newNode = new Node();
    
    // Assign data to the new node
    newNode->data = newData;
    
    // The new node is going to be the last node, so make its next point to NULL
    newNode->next = NULL;

    // If the linked list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse till the last node
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node to point to the new node
    last->next = newNode;
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
    cout << "\n\n****************** Lab 05: Linked List ****************\n\n" << endl;

    int n, value;

    // Initialize head to NULL
    Node* head = NULL;

    // Input the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Insert each element at the end of the linked list
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(&head, value);
    }

    // Print the linked list
    cout << "The linked list is: ";
    printList(head);

    return 0;
}
