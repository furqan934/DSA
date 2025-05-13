#include<iostream>
using namespace std;

class PriorityQueue {
private:
    static const int size = 5;
    struct Element{
        int data ;
        int priority;
    };
    Element arr[size];
    int count ;
public:
      PriorityQueue(){
        count = 0;
      }
      bool isFull(){
        return   count == size ;
      }
      bool isEmpty(){
        return count == 0;
      }
      void enqueue(int value,int priority){
        if (isFull()){
            cout << "Que is oveflow\n";
            return;
        }
        int i = count - 1;
        while (i >= 0 && arr[i].priority > priority ){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1].data = value;
        arr[i+1].priority = priority;
        count ++;
      }
      void dequeue(){
        if (isEmpty()){
            cout <<"Que is underflow!\n";
            return;
        }
        cout << "("<<arr[0].data << ") Dequeued with prioritY("<< arr[0].priority << ")\n";
        // shifting remain element to the right empty slots:
        for (int i = 1 ; i < count ; i++ ){
            arr[i - 1] = arr[i];
        }
        count --;
      }
      
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Priority Queue Elements:\n";
        for (int i = 0; i < count; i++) {
            cout << "Value: " << arr[i].data << ", Priority: " << arr[i].priority << endl;
        }
    }
};
int main(){
    PriorityQueue pq;
     pq.display();
    pq.enqueue(10, 2);
    pq.enqueue(30, 1);
    pq.enqueue(20, 3);
    pq.enqueue(50, 0);
    pq.enqueue(40, 2);
    pq.display();
    pq.dequeue();
    pq.dequeue();
    pq.display();
}