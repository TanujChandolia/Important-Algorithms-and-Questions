#include<iostream>
using namespace std;

struct node
{
   int data;
   node* next;
}*start = nullptr , *finish = nullptr;

void insertStart(int val)
{
   cout<<"Inserting "<<val<< " at start.\n";
   node* temp = new node;
   temp -> data = val;
   temp -> next = nullptr;

   if(start == nullptr)
      {
         start = finish = temp;
         finish -> next = start;
      }
   else
      {
         temp -> next = start;
         start = temp;
         finish -> next = start;
      }
}

void insertMiddle(int val)
{
   cout<<"Inserting "<<val<<" at middle.\n";
   node* fast = start;
   node* slow = start;

   while(fast)
   {
      if(fast == finish || fast -> next == finish)
         break;
      fast = fast -> next -> next;
      slow = slow -> next;
   }

   node* temp = new node;
   temp -> data = val;
   temp -> next = slow -> next;
   slow -> next = temp;
}

void insertEnd(int val)
{
   cout<<"Inserting "<<val<<" at end.\n";
   node* temp = new node;
   temp -> data = val;
   temp -> next = nullptr;
   finish -> next = temp;
   finish = temp;
   finish -> next = start;
}

void delStart()
{
   cout<<"Deleting at the start.\n";
   node* ptr = start;
   start = start -> next;
   finish -> next = start;
   free(ptr);
}

void delMiddle()
{
   cout<<"Deleting at the middle.\n";
   node* fast = start;
   node* slow = start;
   node* save;
   while(fast)
   {
      if(fast == finish || fast -> next == finish)
         break;
      save = slow;
      fast = fast -> next -> next;
      slow = slow -> next;
   }

   node* ptr = slow;
   save -> next = slow -> next;
   free(ptr);
}

void delEnd()
{
   cout<<"Deleting at the end.\n";
   node* temp = start;
   while(temp -> next != finish)
      temp = temp -> next;
   temp ->  next = start;
   free(finish);
   finish = temp;
}
void display()
{
   cout<<"\nLinked List: ";
   node* temp =  start;
   while(temp != finish)
      {
         cout<<temp -> data<<" ";
         temp = temp -> next;
      }
   cout<<finish ->data;
   cout<<endl;
}
int main()
{
   insertStart(10);
   insertStart(20);
   insertStart(30);
   insertStart(40);
   insertStart(50);

   insertMiddle(25);
   insertMiddle(35);

   insertEnd(5);
   insertEnd(0);
   display();

   delStart();
   delStart();

   delMiddle();
   delMiddle();

   delEnd();
   display();
   return 0;
}
