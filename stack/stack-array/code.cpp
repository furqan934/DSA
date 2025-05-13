#include<iostream>
using namespace std ;
class stack{
private:
      static const int size = 100;
      int arr[size];
      int top;
public:
    stack(){
        top = -1;
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == size - 1;
    }
    int peek(){
        if (isEmpty()){
            cout <<" stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    void push(int x){
        if(isFull()){
            cout <<"stack is Full!\n";
            return;
        }
        top ++;
        arr[top] = x;
        cout << x << " is push to the stack\n";
    }
    void pop(){
        if (isEmpty()){
            cout <<" stack is empty\n";
            return;
        }
        cout << arr[top] << ":is poped\n";
        top --;
    }
    int currentSize(){
        if (isEmpty()){
            cout <<" stack is empty.\n";
            return 0;
        }
        return top + 1;

    }
    void diplay(){
        if (isEmpty()){
            cout <<" stack is empty.nothing to display\n";
            return;
        }
        for (int i = 0 ; i <= top ; i ++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.diplay();
    int peekElemnt = s.peek();
    cout << "the peek element is : " << peekElemnt << endl ;
    int curentSize = s.currentSize();
    cout << "the curnrt size of tyhe stack is: " << curentSize << endl ;
    s.diplay();
    s.pop();
    s.diplay();
    
}