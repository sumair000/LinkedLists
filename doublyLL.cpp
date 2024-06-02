#include<iostream>
using namespace std;

class Node{
    public:
    char data;
    Node* next;
    Node* previous;

    Node(char data){
        this->data = data;
        this->next = nullptr;
        this->previous = nullptr;
    }
};

void insertAtHead(Node* &head, char data){
    // list is empty
    if(head == nullptr){
        return;
    }
    // created a new Node
    Node* newNode = new Node(data);
    newNode->next = head;
    head->previous = newNode;
    head = newNode;



}

void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    cout<<endl;
}

int  getLenth(Node* head){
    int lenth = 0;
     Node* temp = head;
    while(temp != nullptr){
        lenth++;
        temp = temp->next;
    }
    return lenth;
}

int main(){
    Node* newNode = new Node('A');

    Node* head = newNode;
    print(head);
    insertAtHead(head, 'B');

    print(head);
}