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

void createNode(Node *&head, int value)
{
    Node *temp = head;
    Node *new_node = new Node(value);

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
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
    int no, value;

    Node *head = NULL;
    cout << "How many nos you want to insert : ";
    cin >> no;

    for (int i = 0; i < no; i++)
    {
        cout << "Enter a number : ";
        cin >> value;
        createNode(head, value);
    }
    printList(head);

    cout << endl;
    return 0;
}