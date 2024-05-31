#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~Node()
    {
        while (this->next != nullptr)
        {
            delete next;
            this->next = nullptr;
        }
    }
};

void insertAtHead(Node *&head, int data)
{

    // create a new node.
    Node *newnode = new Node(data);

    newnode->next = head;
    head = newnode;
}

void insertAtTail(Node *&tail, int data)
{

    // created a new node
    Node *newnode = new Node(data);

    tail->next = newnode;
    tail = newnode;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{

    // if the given is position is 1.
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // if temp-> next is null it means we are at last position
    if (temp->next == nullptr)
    {
        insertAtTail(tail, data);
        return;
    }

    // create a new node which have to insert
    Node *newnode = new Node(data);

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteNode(Node *&head, int position){

    // list is empty
    if (head == nullptr || position < 1)
    {
        return;
    }

    Node *temp = head;
    if (position == 1)
    {
        head = temp->next;
        temp = nullptr;
        delete temp;
        return;
    }

    // find the previous node position
    Node *previous = nullptr;
    int count = 1;
    while (temp != nullptr && count < position)
    {
        previous = temp;
        temp = temp->next;
        count++;
    }

    // upper boundary limit
    if (temp == nullptr)
    {
        return;
    }
    previous->next = temp->next;
    temp = nullptr;
    delete temp;
}

void print(Node *&head)
{

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(5);

    Node *head = node1;
    Node *tail = node1;

    print(head);
    insertAtHead(head, 7);
    print(head);
    insertAtTail(tail, 9);
    print(head);
    insertAtPosition(head, tail, 8, 2);
    print(head);

    deleteNode(head, 0);
    print(head);
}