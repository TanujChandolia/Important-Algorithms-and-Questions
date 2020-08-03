#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node* back;
  struct node* next;
} *start = NULL , *finish = NULL;

void insert(int val)
{
   cout<<"Inserted "<<val<<endl;
  struct node* temp;
  temp = new node();
  temp -> data = val;

  if(start == NULL)
  {
    start = finish = temp;
    start -> back = NULL;
    finish -> next = NULL;
  }

  else
  {
    finish -> next = temp;
    temp -> back = finish;
    finish = temp;
    finish -> next = NULL;
  }
}

void deleteL(int val)
{
  struct node* temp;
  struct node* ptr;

  temp = start;
  while(temp != NULL)
  {
    if(temp -> data == val)
    {
      ptr = temp;
      temp -> back -> next = temp -> next;
      temp -> next -> back = temp -> back;
      cout<<"\nValue deleted.\n";
      free(ptr);
    }
    temp = temp -> next;
  }
}

void insertAfter(int after ,int val)
{
  struct node* temp;
  struct node* ptr;

  ptr = new node();
  ptr -> data = val;

  temp =  start;
  while(temp != NULL)
  {
    if(temp -> data == after)
    {
      ptr -> next = temp -> next;
      temp -> next -> back = ptr;
      temp -> next = ptr;
      ptr -> back = temp;
      cout<<"\nValue inserted in between.\n";
    }
    temp = temp -> next;
  }
}

void display()
{
  struct node* temp;
  temp = start;
  cout<<"Display in forward manner:\n";
  while(temp != NULL)
  {
    cout<<temp -> data<<" ";
    temp = temp -> next;
  }

  cout<<"\nDisplay in reverse manner:\n";
  temp = finish;
  while(temp != NULL)
  {
    cout<<temp -> data<<" ";
    temp = temp -> back;
  }
}

int main()
{
  insert(5);
  insert(10);
  insert(15);
  display();

  deleteL(10);

  display();

  insertAfter(5,12);
  display();
  return 0;
}
