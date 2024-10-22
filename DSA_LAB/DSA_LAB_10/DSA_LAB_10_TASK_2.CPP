#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    
    if(root == nullptr) {
        return createNode(value);
    }
    
    if(value < root->data) {

        root->left = insert(root->left, value);
    } else if(value > root->data) {
    
        root->right = insert(root->right, value);
    }
    return root;
}

void preOrderTraversal(Node* root) {
    if(root == nullptr) {
        return;
    }
    cout << root->data << " ";          
    preOrderTraversal(root->left);      
    preOrderTraversal(root->right);      
}

int main() {
    Node* root = nullptr;   
    int nodes, n;

    cout << "Enter the number of nodes you want to enter: ";
    cin >> nodes;
    for(int i = 0; i < nodes; i++) {
        cout << "Enter the value for Node " << i+1 << ": ";
        cin >> n;
        root = insert(root, n);  
    }
    cout << "Pre-order Traversal of the BST: ";
    preOrderTraversal(root);
    
    return 0;
}
