#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void print_list(Node *ptr)
{
    Node *temp = ptr;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void create_node(Node *&ptr, int num)
{
    Node *new_node = new Node();
    new_node->data = num;
    new_node->next = NULL;

    if (ptr == NULL)
    {
        ptr = new_node;
        return;
    }

    Node *temp = ptr;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

int main()
{
    int num, element;
    Node *head = NULL;

    cout << "How many no you want to insert : ";
    cin >> num;

    cout << "Enter the numbers : ";
    for (int i = 0; i < num; i++)
    {
        cin >> element;
        create_node(head, element);
    }

    print_list(head);

    cout << endl;
    return 0;
}
