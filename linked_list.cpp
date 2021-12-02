#include <iostream>
using namespace std;
class Node {
   public:
   int data;
   Node *next_node;
};
Node* head_node = NULL;

void insert(int new_data) {
   Node* new_node = (Node*) malloc(sizeof(Node));

   new_node->data = new_data; 
   new_node->next_node = head_node;
   head_node = new_node;
}
void display() {
   Node* ptr;
   ptr = head_node;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next_node;
   }
}
int main() {
   int n,num,i;
   cout<<"\nHow many numbers do u want to insert: ";
   cin>>n;
   for(i=0;i<n;i++)
   {
       cout<<(i+1)<<".Enter the number: ";
       cin>>num;
       insert(num);
   }
   
   cout<<"\nThe linked list is: ";
   display();
   cout<<"\n";
   return 0;
}