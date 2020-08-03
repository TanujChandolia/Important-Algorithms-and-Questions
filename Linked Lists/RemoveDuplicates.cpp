#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node* next;
}*start = NULL , *finish = NULL;

void insert(int val)
{
  struct node* temp;
  temp = new node();
  temp -> data = val;

  if(start == NULL)
      start = finish = temp;
  else
    {
      finish -> next = temp;
      finish = temp;
      finish -> next = NULL;
    }
}


void display()
{
  struct node* temp;
  temp = start;
  while(temp!=NULL)
  {
    cout<<temp -> data<<" ";
    temp = temp -> next;
  }
  cout<<endl;
}

void removeDuplicates()
{
  struct node* temp;
  temp = start;
  while(temp -> next != NULL)
  {
          while(temp -> data == temp -> next -> data)
          {
                    temp -> next = temp -> next -> next;
                    if(temp -> next == NULL)
                        return;
          }
      temp = temp -> next;
  }
}

int main()
{
  insert(1);
  insert(1);
  insert(2);
  insert(3);
  insert(3);
  insert(5);
  insert(5);
  insert(5);
  insert(6);
  insert(6);
  insert(6);


  display();
  removeDuplicates();
  display();
  return 0;
}
