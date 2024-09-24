#include<iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;        // Data to store
    Node* next;      // Pointer to the next node
};

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();  // Allocate memory for new node
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;  // If the list is empty, make the new node the head
        return;
    }

    Node* last = *head;  // Otherwise, traverse to the end of the list
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;  // Insert the new node at the end
}

// Function to delete a node with a specific key
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;  // If the node to be deleted is the head
        delete temp;         // Free the old head
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

    prev->next = temp->next;  // Unlink the node from the list
    delete temp;              // Free memory
    cout << "Node with value " << key << " deleted successfully." << endl;
}

// Function to search for a node with a specific key
bool searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return true;  // Key found
        }
        current = current->next;
    }
    return false;  // Key not found
}

// Function to print the linked list
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

    // Create a linked list with 5 nodes
    cout << "Enter values for 5 nodes:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(&head, value);
    }

    // Print the linked list
    cout << "The linked list is: ";
    printList(head);

    // Perform a search operation
    cout << "Enter value to search: ";
    cin >> value;
    if (searchNode(head, value)) {
        cout << "Value " << value << " found in the list." << endl;
    } else {
        cout << "Value " << value << " not found in the list." << endl;
    }

    // Perform a deletion operation
    cout << "Enter value to delete: ";
    cin >> value;
    deleteNode(&head, value);

    // Print the linked list after deletion
    cout << "The linked list after deletion is: ";
    printList(head);

    return 0;
}
