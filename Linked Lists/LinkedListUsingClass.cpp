#include<iostream>

using namespace std;

class node
{
public:
     int data;
     node *next;
};

class LinkedList
{
   node *head , *tail;
public:
   LinkedList()
   {
      head = NULL;
      tail = NULL;
   }
   void insert(int);
   void display();
};

void LinkedList::insert(int val)
   {
      node* temp = new node;
      temp -> data = val;
      temp -> next = NULL;

      if(head == NULL)
         {
            head = temp;
            tail = temp;
         }
      else
         {
            tail -> next = temp;
            tail = temp;
         }
   }

void LinkedList::display()
{
   node *temp = head;
   while(temp != NULL)
      {
         cout<<temp -> data<<" ";
         temp = temp -> next;
      }
}
int main()
{
   LinkedList l;
   l.insert(10);
   l.insert(20);
   l.insert(30);
   l.display();
   return 0;
}
