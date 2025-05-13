

#include <iostream>
using namespace std;

// Define stack of fixed size 10
const int SIZE = 10;
int stack[SIZE];
int top = -1; // stack is initially empty

// Function to display initial status
void Declare_Stack() {
    cout << "Stack of size " << SIZE << " has been declared." << endl;
    cout << "Top initialized to -1 (stack is empty)." << endl;
}

int* Declare_Stack_Dynamic(int &size) {
    cout << "Enter the size of the stack: ";
    cin >> size;
    int* stack = new int[size];
    return stack;
}
int Stack_Size(int top) {
    return top + 1;
}
bool Is_Empty(int top) {
    return top == -1;
}
bool Is_Full(int top, int size) {
    return top == size - 1;
}
void Push(int stack[], int &top, int size, int value) {
    if (top == size - 1) {
        cout << "Stack Overflow! Cannot push " << value << endl;
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed into stack." << endl;
    }
}

void Pop(int stack[], int &top) {
    if (top == -1) {
        cout << "Stack Underflow! Cannot pop." << endl;
    } else {
        cout << stack[top] << " popped from stack." << endl;
        top--;
    }
}