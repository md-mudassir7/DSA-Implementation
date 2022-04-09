#include<bits/stdc++.h>
using namespace std;
class Stack{
private:
    int top;
    int* arr;
    int capacity;
public:
    Stack(int size){
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    void push(int value){
        if(isFull()){
            cout<<"Stack Overflow\n";
            return;
        }
        else{
            top++;
            arr[top] = value;
            return;
        }
    }
    int pop(){
        if(isEmpty())
        {
            cout<<"Stack Underflow\n";
            return 0;
        }
        else{
            int popped = arr[top];
            top--;
            return popped;
        }
    }
    int peek(){
        if (top < 0) {
            cout << "Stack is Empty";
            return 0;
        }
        else {
            int x = arr[top];
            return x;
        }
    }
    bool isEmpty(){
        return top<0;
    }
    bool isFull(){
        return top==capacity-1;
    }
    void printStack(Stack s){
        Stack temp = s;
        while(!temp.isEmpty()){
            cout<<temp.peek()<<" ";
            temp.pop();
        }
        cout<<endl;
        return;
    }
};
int main(){
    Stack s(100);
    s.push(10);
    s.push(20);
    s.push(30);
    s.printStack(s);
    s.pop();
    s.printStack(s);
    return 0;
}