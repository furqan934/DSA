#include<iostream>
using namespace std;
class Que{
    private:
        static const int SIZE = 5;
         int arr[SIZE];
         int head ;
         int tail ;
    public:
         Que(){
             head = 0;
             tail = 0;
         }   
         bool isEmpty(){
            return head == tail;
         }
         bool isFull(){
            return tail == SIZE;
         }
         void enqueue(int value ){
            if (isFull()){
                cout <<"que is overflow!\n";
                return;
            }
            tail = tail ++;
            arr[tail] = value;
            cout << value <<" enqueud\n";
         }
         void dequeue(){
            if (isEmpty()){
                cout <<"que is underflow!\n";
                return ;
            }
            cout << arr[head] <<"dequeued!\n";
            head ++;
         }
         void display(){
            for ( int i = head; i <= tail ; i ++)
            {
                cout << arr[i] << " ";
            }
             cout << endl;
         }
        };
int main(){
            Que q;
            q.enqueue(10);
            q.enqueue(20);
            q.enqueue(30);
            q.enqueue(40);
            q.enqueue(50);
            q.display();
            return 0;
             }


   