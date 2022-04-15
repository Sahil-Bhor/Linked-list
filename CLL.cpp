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

void createNode(Node *&head, Node *&tail, int value)
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
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node;
        tail = new_node;
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
    cout << temp->data;
}

int main()
{
    int value;
    Node *head = NULL;
    Node *tail = head;
    createNode(head, tail, 34);
    createNode(head, tail, 49);
    createNode(head, tail, 61);
    createNode(head, tail, 76);
    createNode(head, tail, 16);
    printList(head);

    printf("\nThe head is %d", head->data);
    printf("\nThe tail is %d\n", tail->data);

    cout << endl;
    return 0;
}