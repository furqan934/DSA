#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
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
        Node*  head = new Node{10,nullptr};
        Node*   secend = new Node{20,nullptr};
        Node*   third = new Node{30,nullptr};


        head->next = secend;
        secend->next = third;

        cout <<"linked list : ";
        traversing(head);


    }

    
