#include<iostream>
using namespace std ;
class que{
    private:
    const int static size = 5;
    int front , rear;
    int arr[size];
    public:
    que()
    {
        front = rear = -1;
    }
    bool isEmpty()
    {
        return front == -1 || front > rear;
    }
    bool idFull()
    {
        return rear == size - 1;
    }
    void enQue(int value)
    {
        if(idFull())
        {
            cout << "arr is overflow ";
            return;
        }
        if (front = -1)
        {
            front  = 0;
        }
        rear ++;
        arr[rear] = value;
        cout << value << " enqueued\n";

    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        front++;
    }
    void peek(){
        if (isEmpty()){
            cout << " the que is empty!\n";
            return;
        }
        cout << arr[front] << "is the peek of the que \n";
    }
    int currentSize(){
        if (isEmpty()){
            return 0;
        }
        return(rear - front + 1);
    }  
      // Display queue
      void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    que q;

    q.enQue(10);
    q.enQue(20);
    q.enQue(30);
    q.enQue(40);
    q.enQue(50);
    q.display();
    q.peek();
    cout << "Current size: " << q.currentSize() << endl;



    q.dequeue();
    q.display();

    q.dequeue();
    q.display();
    cout << "Current size: " << q.currentSize() << endl;

}