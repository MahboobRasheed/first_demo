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
void inOrder(Node* root, int* sortedArray, int &index) {
    if(root != nullptr) {
        inOrder(root->left, sortedArray, index);
        sortedArray[index++] = root->data;  
        inOrder(root->right, sortedArray, index);
    }
}

void bstSort(int* array, int size) {
    Node* root = nullptr;
    for(int i = 0; i < size; i++) {
        root = insert(root, array[i]);
    }

    int index = 0;
    inOrder(root, array, index);  
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* array = new int[size];

    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }

    bstSort(array, size);

    cout << "Sorted array: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array; 
    return 0;
}
