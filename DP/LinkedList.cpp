#include<bits/stdc++.h>
using namespace std;

class Node{

    public: 
        int data;
        Node* next;
        Node()
        {
            int data = 0;
            next = NULL;
        }
        Node(int x)
        {
            int data = x;
            next = NULL;
        }
};

class Linkedlist{

    Node* head;
    public:
    Linkedlist(){head = NULL};
    void insert(int data);

};

void Linkedlist::insert(int x)
{
    Node* newNode = new Node(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    
}
