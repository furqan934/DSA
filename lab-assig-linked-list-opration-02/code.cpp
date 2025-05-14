#include<iostream>
#include<cmath>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

// 1. Display all the elements of the list
void display(Node* head){
    if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "--> "; 
          temp =  temp -> next  ;
    }
    cout << "Null" << endl;
}
//insert value at end
void insertAtEnd(Node*& head,int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << "value: "<<value << " is inserted " << endl;
}
// insertion a nvalue  after  given value 
  void insertAfterValue(Node*& head,int newValue,int afterValue) {
        Node* temp = head;
        while (temp != nullptr && temp->data != afterValue) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Value: "<< afterValue<<" not found!" << endl;
            return;
        }
        
        Node* newNode = new Node(newValue);
        cout << "New value: " << newValue <<" is inserted after value: " << afterValue  << endl;
        newNode->next = temp->next;
        temp->next = newNode;
    }
// delte value 
void deleteNode(Node*& head , int k)
{
    int position = 0;
    if (head == NULL)
    {
        cout << "the list is empty!.\n";
        return;
    }
    Node* temp = head;
    if (temp->data == k)
    {
        cout <<"value: "  << k << " is deleted  at position " << position << endl; 
        head = temp->next;
        return;
    }
    Node* pred = temp;
    temp = temp->next;
    
    while (temp != nullptr)
    {
        if (temp-> data = k)
        {
            cout <<"value: "  << k << " is deleted  at position " << position << endl;
            pred->next = temp->next;
            return;
        }
        pred = temp;
        temp = temp->next;
        position ++;
    }
}
 // Search for an value
void searchElement(Node* head,int value) {
        int position = 1;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Value: " << value << " found at position " << position << ".\n";
                return;
            }
            else{
                cout <<"Value: "<< value << "are not founded" << endl;
            }
            temp = temp->next;
            position ++;
        }
    }
// statistics:    
void reportStatistics(Node* head){
    if(head == nullptr){
        cout << "the list is empty!.\n";
        return;
    }
    int value;
    int count = 0;
    int sum = 0;
    int minValue = head->data;
    int maxValue = head ->data;
    Node* temp = head;
    while (temp != nullptr)
    {
       value = temp -> data;
       sum += value;
       if (value < minValue){
        minValue = value;
       }
       if( value >  maxValue){
        maxValue = value;
       }
       count ++;
       temp = temp -> next;
    }
    double average = (double) sum / count ;

    double varience = 0.0;
    temp = head;
    while (temp != nullptr)
    {
       
        varience += pow(temp->data - average, 2);
        temp = temp->next;
    }
    varience /= count;
    double stdDeviation = sqrt(varience);
    cout <<"Statistics: "<<endl;
    cout << "Min Valu: "<< minValue<< endl;
    cout << "Max Valu: "<< maxValue<< endl;
    cout << "Average: "<< minValue<< endl;
    cout << "Standard Deviation::"<< stdDeviation<< endl;
}
// display avrage :
void displayInRange(Node* head, int k, int d) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    int lower = k - d;
    int upper = k + d;
    cout << "Elements in range [" << lower << ", " << upper << "]: ";
    Node* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->data >= lower && temp->data <= upper) {
            cout << temp->data << " ";
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "None";
    cout << "\n";
}
int main() {
    Node* head = nullptr;
    int choice, value, afterValue, minRange, maxRange;

        do{
        cout << "\n1). Display all elements of the list\n";
        cout << "2). Insert a node at the end\n";
        cout << "3). Insert a node after a given value\n";
        cout << "4). Delete a node\n";
        cout << "5). Search for an element\n";
        cout << "6). Report Statistics (Min, Max, Ave, Std Dev)\n";
        cout << "7). Display elements in a given range\n";
        cout << "8). Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                display(head);
                break;
            case 2:
                cout << "Enter the value to insert: ";
                cin >> value;
                insertAtEnd(head,value);
                break;
            case 3:
                cout << "Enter the value that you want to insert after: ";
                cin >> afterValue;
                cout << "Enter the new value to insert: ";
                cin >> value;
                insertAfterValue(head,value,afterValue);
                break;
            case 4:
                cout << "Enter the value to delete: ";
                cin >> value;
                deleteNode(head,value);
                break;
            case 5:
                cout << "Enter the value to search for: ";
                cin >> value;
                searchElement(head,value);
                break;
            case 6:
                reportStatistics(head);
                break;
            case 7:
                cout << "Enter the min range: ";
                cin >> minRange;
                cout << "Enter the max range: ";
                cin >> maxRange;
                displayInRange(head,minRange, maxRange);
                break;
            case 8:
                cout << "Quit" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }
        while (choice != 8);   
}