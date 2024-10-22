#include<iostream>
using namespace std;
struct Node 
{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) 
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
Node* insert(Node* root, int value) 
{
    if(root == nullptr) 
    {
        return createNode(value);
    }
    if(value < root->data) 
    {
        root->left = insert(root->left, value);
    } 
    else if(value > root->data) 
    {
        root->right = insert(root->right, value);
    }
    return root;
}
bool search(Node* root, int value) 
{
    if(root == nullptr) 
    {
        return false;  
    }
    if(root->data == value) 
    {
        return true;   
    }

    if(value < root->data) 
    {
        return search(root->left, value); 
    } 
    else 
    {
        return search(root->right, value); 
    }
}
int main() 
{
    Node* root = nullptr;    
    int nodes, n, searchValue;
    cout << "Enter the number of nodes you want to enter: ";
    cin >> nodes;
    
    for(int i = 0; i < nodes; i++) 
    {
        cout << "Enter the value for Node " << i+1 << ": ";
        cin >> n;
        root = insert(root, n);  
    }

    cout << "Enter the value to search in the BST: ";
    cin >> searchValue;
    if(search(root, searchValue)) 
    {
        cout << "Value " << searchValue << " found in the BST." << endl;
    } 
    else 
    {
        cout << "Value " << searchValue << " not found in the BST on any position." << endl;
    }   
    return 0;
}
