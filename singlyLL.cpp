#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtHead(Node* &head, int data){

    // create a new node.
    Node* newnode = new Node(data);

    newnode->next = head;
    head = newnode;
}


int main(){
    Node* node1 = new Node(5);

    Node* head = node1;

    cout<<node1->data;

}