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

void inOrder(Node* root) {
    if(root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if(root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function for Post-order traversal (Left, Right, Root)
void postOrder(Node* root) {
    if(root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
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
    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}
