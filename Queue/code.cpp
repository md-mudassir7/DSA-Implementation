#include<bits/stdc++.h>
using namespace std;
class Queue{
private:
    int *arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue
public:
    // Constructor to initialize a queue
    Queue(int size = 100){
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    //function to dequeue the front element
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == capacity;
    }
    int deQueue(){
        if(isEmpty()){
            cout<<"Underflow\n";
            exit(EXIT_FAILURE);
        }
        int x = arr[front];
        front = (front+1)%capacity;
        count--;
        return x;
    }
    void enQueue(int data){
        if(isFull()){
            cout<<"Overflow\n";
            exit(EXIT_FAILURE);
        }
        rear = (rear+1)%capacity;
        arr[rear] = data;
        count++;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Underflow\n";
            exit(EXIT_FAILURE);
        }
        return arr[front];
    }
    int size(){
        return count;
    }
};
int main(){
    Queue q(100);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    cout << "The front element is "<<q.peek()<<endl;
    q.deQueue();
    cout << "The front element is "<<q.peek()<<endl;
    q.enQueue(4);
    cout << "The queue size is " << q.size() << endl;
    return 0;
}