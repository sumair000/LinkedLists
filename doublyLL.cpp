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

void insertAtHead(Node* &head,Node* &tail, char data){
    // list is empty
    if(head == nullptr){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{

        Node* newNode = new Node(data);

        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    
    
}

void insertAtTail(Node* &tail,Node* &head, char data){

    if (tail == nullptr)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    
    else{

        Node* newNode = new Node(data);

        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    

}

void insertAtPosition(Node* &head, Node* &tail, int position, char data){

    // if the given is position is 1.
    if (position == 1)
    {
        insertAtHead(head,tail, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1 && temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr)
    {
        return;
    }
    
     // if temp-> next is null it means we are at last position
    if (temp->next == nullptr)
    {
        insertAtTail(tail,head, data);
        return;
    }

    // create a new node which have to insert
    Node *newNode = new Node(data);

    newNode->next = temp->next;
    temp->next->previous = newNode;
    temp->next = newNode;
    newNode->previous = temp;


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
    //Node* newNode = new Node('A');

    Node* head = nullptr;
    Node* tail = nullptr;
    print(head);

    insertAtHead(head,tail, 'B');
    print(head);


    insertAtTail(tail,head,'C');
    print(head);

    insertAtPosition(head,tail,7,'D');
    print(head);


}