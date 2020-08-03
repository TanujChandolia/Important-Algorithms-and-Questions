#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node* next;
} *start;

void insertStart(int val)
{
   cout<<"Inserting "<<val<< " at start of the linked list.\n";
   node* temp = new node;
   temp -> data = val;
   temp -> next = NULL;

   if(start == NULL)
      start = temp;
   else
      {
         temp -> next = start;
         start = temp;
      }
}

void insertMiddle(int val)
{
   cout<<"Inserting "<<val<<" at the middle of the linked list.\n";
   node* fast = start;
   node* slow = start;

   while(fast -> next)
   {
      if(fast -> next == NULL || fast -> next -> next == NULL)
         break;
      else
         fast = fast -> next ->  next;
      slow = slow -> next;
   }
   node* temp = new node;
   temp -> data = val;
   temp -> next = NULL;

   temp -> next = slow -> next;
   slow -> next = temp;
}

void insertEnd(int val)
{
   cout<<"Inserting "<<val<<" at the end of the list.\n";

   node* ptr = start;
   while(ptr -> next)
      ptr = ptr -> next;

   node *temp = new node;
   temp -> data = val;
   temp -> next = NULL;
   ptr -> next = temp;

}

void delStart()
{
   cout<<"Deleting "<<start -> data<<" at the start.\n";
   node *ptr = start;
   start = start -> next;
   free(ptr);
}

void delMiddle()
{
   node* fast = start;
   node* slow = start;
   node* save;
   while(fast -> next)
   {
      save = slow;
      if(fast -> next == NULL || fast -> next -> next == NULL)
         break;
      else
         fast = fast -> next ->  next;
      slow = slow -> next;
   }

   cout<<"Deleting "<<slow-> data<<" at the middle of the list.\n";
   node* ptr = slow;
   save -> next = slow -> next;
   free(ptr);
}

void delEnd()
{
   node* ptr = start;
   while(ptr -> next -> next)
      ptr = ptr -> next;

   cout<<"Deleting "<<ptr -> next -> data<<" at the end of list.\n";
   node*  save = ptr -> next;
   ptr -> next = NULL;
   free(save);
}
void display()
{
   node *temp = start;
   cout<<"\nLinked list: ";
   while(temp)
      {
         cout<<temp -> data<<" ";
         temp = temp -> next;
      }
   cout<<endl;
}
int main()
{
   insertStart(10);
   insertStart(20);
   insertStart(30);
   insertStart(40);

   insertMiddle(25);
   insertMiddle(35);

   insertEnd(5);
   insertEnd(0);

   display();

   delStart();
   delStart();
   delStart();

   delMiddle();

   delEnd();
   display();
  return 0;
}
