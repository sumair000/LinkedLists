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

int main(){
    Node* node1 = new Node(5);

    cout<<node1->data;

}