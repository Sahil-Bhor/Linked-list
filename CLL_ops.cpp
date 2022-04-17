#include <iostream>
#define size 10
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAfter(Node *&head, Node *&tail, int after, int value)
{
    Node *new_node = new Node(value);
    Node *temp = head;
    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
        tail = head;
    }

    else
    {
        while (temp->data != after)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;

        while (temp->next != head)
        {
            temp = temp->next;
        }
        tail = temp;
    }
}

void printList(Node *&head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void deleteAfter(Node *&head, int after)
{
    Node *temp = head;
    while (temp->data != after)
    {
        temp = temp->next;
    }
    Node *todelete = temp->next;
    temp->next = todelete->next;
    todelete->next = NULL;
    delete (todelete);
}

int main()
{
    int value;
    Node *head = NULL;
    Node *tail = head;

    insertAfter(head, tail, 4, 43);
    insertAfter(head, tail, 43, 7);
    insertAfter(head, tail, 7, 9);
    insertAfter(head, tail, 7, 32);
    printList(head);
    deleteAfter(head, 7);
    printList(head);

    printf("\nThe head is %d", head->data);
    printf("\nThe tail is %d\n", tail->data);

    cout << endl;
    return 0;
}