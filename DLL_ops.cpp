#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;

    Node() {}
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(Node *&head, int value)
{
    Node *new_node = new Node(value);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}

void insertAtTail(Node *&tail, int value)
{
    Node *new_node = new Node(value);
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    int count = 1;
    Node *temp = head;

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;

        temp->next = NULL;
        temp->prev = NULL;
        delete (temp);
    }
    else
    {

        while (count < position)
        {
            temp = temp->next;
            count++;
        }
        if (temp->next == NULL)
        {
            tail = temp->prev;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        temp->next = NULL;
        temp->prev = NULL;

        delete (temp);
    }
}

void printList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(23);
    Node *tail = head;

    insertAtHead(head, 55);
    insertAtTail(tail, 89);
    insertAtHead(head, 15);
    insertAtTail(tail, 63);

    printList(head);
    deleteNode(head, tail, 1);
    printList(head);

    insertAtTail(tail, 100);
    printList(head);

    printf("\nThe head is %d", head->data);
    printf("\nThe tail is %d\n", tail->data);

    cout << endl;
    return 0;
}