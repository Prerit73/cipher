#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(){
        Node(0);
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *takeInput()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1) // take input till we give -1
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode; // tail=tail->next
        }
        cin >> data;
    }
    return head;
}

Node *merge(Node *head1, Node *head2){
    Node *fh=NULL;
    Node *ft=NULL;
    
    if(fh == NULL)
    {
        if(head1->data <= head2->data)
        {
            fh=head1;
            ft=head1;
            head1=head1->next;
        }
        else
        {
            fh=head2;
            ft=head2;
            head2=head2->next;
        }
    }
    
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            ft->next = head1;
            ft=head1;
            head1 = ft->next;
        }
        else
        {
            ft->next = head2;
            ft=head2;
            head2 = ft->next;
        }
    }
    if(head2==NULL)
    ft->next=head1;
    else
    ft->next=head2;
    
    
    return fh;
}

void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    Node *head1 = takeInput();
    Node *head2 = takeInput();
    
    Node *head=merge(head1,head2);
    
    print(head);
    
}