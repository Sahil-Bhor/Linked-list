#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {}

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print_list(Node *&head)
{
    cout << "-> ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int val)
{
    Node *new_node = new Node(val);
    // new_node->data = val;
    new_node->next = head;
    head = new_node;
}

void insertAtTail(Node *&tail, int val)
{
    Node *temp = tail;

    Node *new_node = new Node(val);
    temp->next = new_node;
    tail = new_node;
}


void deleteNode(Node *&head, Node *&tail, int position)
{
    int count = 1;
    Node *current = head;
    Node *prev = NULL;

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete (temp);
    }

    while (count < position)
    {
        prev = current;
        current = current->next;
        count++;
    }
    if (current->next == NULL)
    {
        tail = prev;
    }
    prev->next = current->next;
    current->next = NULL;
    delete (current);
}

int main()
{

    Node *head = NULL;

    insertAtHead(head, 34);
    print_list(head);

    Node *tail = head; // condition it should be placed/initialised before a head

    insertAtHead(head, 59);
    print_list(head);

    insertAtTail(tail, 21);
    print_list(head);
    insertAtTail(tail, 89);
    print_list(head);

    deleteNode(head, tail, 4);
    print_list(head);

    printf("\nThe head is %d", head->data);
    printf("\nThe tail is %d\n", tail->data);

    cout << endl;
    return 0;
}
