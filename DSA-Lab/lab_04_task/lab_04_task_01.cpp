#include<iostream>
using namespace std;
//Define the structure for a node
struct Node{
    int data;          //Data to store
    Node* next;         //pointer to next node
};
//function to insert a node at a beginning
    void insertAtBeginning(Node** head, int newData){
        //allocate memory for new node
        Node* newNode=new Node();
        //assign data to the new node
        newNode->data=newData;
        //make next of new node  point to the cutrrent head
        newNode->next=*head;
        //move the head to point to the new node
        *head=newNode;
    }
    void List(Node* node){
        while(node !=nullptr){
            cout<<node->data<<" -> ";
            node=node->next;
        }
        cout<<"NULL"<<endl;
    }
    int main()
    {
        cout<<"\n\n******************lab 05 linkedlist****************\n\n"<<endl;
        int n;
        cout<<"how many values do you ewant to insert at te beginning of the list";
        cin>>n;
        Node* head=nullptr;
        for(int i=0; i<n; i++){
            cout<<i+1<<"value is "<<" :";
            int value;
            cin>>value;
            insertAtBeginning(&head,value);

        }
        cout<<"the linked list is:";
        printList(head);
        return 0;
    }

