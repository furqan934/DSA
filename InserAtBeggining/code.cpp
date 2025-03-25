#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data )
    {
        this->data=data;
        this->next=nullptr;
    }
};
// function to insert AT begining.
void insetAtBegin(Node*& head , int newData)
{
    Node* newNode = new Node(newData);
    newNode -> next = head;
    head = newNode;
}
// printing the linked list .
void traversing(Node* head)
{
    
    Node* currunt = head;
    if (head == nullptr)
    {
       cout <<" nothing to display the list is empty " << endl;
       return;
    }
    while (currunt != nullptr)
    {
        cout << currunt ->data <<"->";
        currunt = currunt->next;
    }
    cout << "Null";
}

int main()
{
    Node* head = nullptr;
    insetAtBegin(head,10);
    insetAtBegin(head,20);
    cout <<"after inserting element at beginging in linked list " << endl;
    traversing(head);



}