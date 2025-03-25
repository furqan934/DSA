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
// function to insert AT specific oposition.
void insertAtPosition(Node*& head,  int newData , int position)
{
    Node* newNode = new Node (newData);
    if (position == 1)
    {
        newNode -> next = head;
        head  = newNode ;
        return;
    }
    Node* curnt = head;
    for (int i = 1; curnt != nullptr && i < position - 1; i++)
    {
        curnt = curnt->next;
    }
    if(curnt == nullptr)
    {
        cout <<"position out of range " <<  endl;
         delete newNode;
         return;
    }
    newNode -> next = curnt->next;
    curnt -> next = newNode;
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
        cout <<"[" << currunt ->data << "]" <<"->";
        currunt = currunt->next;
    }
    cout << "Null" << endl;
}

int main()
{
    Node* head = nullptr;
    insetAtBegin(head,10);
    insetAtBegin(head,20);
    cout <<"after inserting element at beginging in linked list " << endl;
    traversing(head);
    insertAtPosition(head,15,2);
    cout <<"after inserting element at specific position in linked list " << endl;
    traversing(head);
    

}