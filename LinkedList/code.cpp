#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }
    void insert(int data){
        Node* toInsert = new Node(data);
        if(head==NULL){
            head = toInsert;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = toInsert;
        return;
    }
    void deleteNodeAtPosition(int position){
        if(head->data==position){
            head = head->next;
            return;
        }
        Node* temp = head;
        while(temp->next->data!=position){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete(temp->next);
        return;
    }
    void printList(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
        return;
    }
};
int main(){
    LinkedList list;
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.printList();
    list.deleteNodeAtPosition(2);
    list.printList();
    return 0;
}