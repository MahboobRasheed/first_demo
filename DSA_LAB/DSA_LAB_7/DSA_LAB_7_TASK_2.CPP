#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
void insertatbeginning(Node** head, int data) {
    Node* newNode = new Node();  
    newNode->data = data;         
    newNode->next = *head;        
    *head = newNode;              
}
void deleteatbeginning(Node** head) {
    if (*head == nullptr) return;  
    Node* temp = *head;            
    *head = (*head)->next;         
    delete temp;                   
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
    insertatbeginning(&head, 30);
    insertatbeginning(&head, 20);
    insertatbeginning(&head, 10);
    printforward(head);  
    deleteatbeginning(&head);
    printforward(head); 

    return 0;
}
