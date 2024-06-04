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

    ~Node(){
        while(this->next != nullptr){
            delete next;
            this->next = nullptr;
        }
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

void deleteNodeP(Node* &head, int position){
    // list is empty
    if (head == nullptr || position < 1)
    {
        return;
    }
    
    Node* temp = head;
     if (position == 1)
    {
        head = temp->next;
        temp->next->previous = nullptr;
        temp->next = nullptr;
        delete temp;
        return;
    }

    Node* pre = nullptr;
    int count = 1;
    while(temp != nullptr && count < position){
        pre = temp;
        temp = temp->next;
        count++;

    }
    if(temp == nullptr){
        return;
    }

    temp->previous = nullptr;
    pre->next = temp->next;
    temp->next = nullptr;

    delete temp;
    
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
    Node* tail = newNode;
    print(head);

    insertAtHead(head,tail, 'B');
    print(head);


    insertAtTail(tail,head,'C');
    print(head);

    insertAtPosition(head,tail,2,'D');
    print(head);

    deleteNodeP(head,1);
    print(head);

}