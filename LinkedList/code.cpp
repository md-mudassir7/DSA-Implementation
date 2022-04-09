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
        if (head == NULL){
            // if list is empty do nothing
            cout<<"List is Empty"<<endl;
        }
        else{
            
            if (position == 0) {
                Node *temp = head;
                // if p==0, perform delete at beginning
                cout<<"Element Deleted: "<<head->data<<endl;
                head = head->next;
                delete(temp);
            }
            else{
                // if p > 0
                // set ptr to pth Node and temp to (p-1)th Node
                Node* temp = head;
                position--; //Since to delte a node we wanna be at a node previous to it
                while(position>0){
                    position--;
                    temp = temp->next;
                }
                cout<<"Element Deleted: "<<temp->next->data<<endl;
                // set next of (p-1)th Node to next of pth Node
                temp->next = temp->next->next;
                // free pth Node
                free(temp->next);
            }
        }

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