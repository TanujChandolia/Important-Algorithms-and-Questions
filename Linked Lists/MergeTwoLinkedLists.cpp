#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node* next;
}*start1 = NULL, *start2 = NULL,*finish1 = NULL, *finish2 = NULL;

void insert(int x , struct node** start , struct node** finish)
{
  struct node* temp;
  temp = new node();
  temp -> data = x;

  struct node *s , *f;
  s = *start;
  f = *finish;

  if(s == NULL)
      *start = *finish = temp;
  else
  {
    f -> next = temp;
    *finish = temp;
    f = temp;
    f -> next = NULL;
  }

}

void display(node* start)
{
  node* temp;
  temp = start;
  while(temp != NULL)
  {
    cout<<temp -> data<<" ";
    temp = temp -> next;
  }
  cout<<endl;
}

node* mergeList(node* start1 , node* start2){
   node* head = new node;
   head -> data = -1;
   head -> next = nullptr;
   node* tail = head;

   while(start1 && start2){
      if(start1 -> data < start2 -> data){
         tail -> next = start1;
         tail = start1;
         start1 = start1 -> next;
      }
      else{
         tail -> next = start2;
         tail = start2;
         start2 = start2 -> next;
      }
   }

   if(start1 == nullptr)
      tail -> next = start2;
   else
      tail -> next = start1;

   return head -> next;
}

int main()
{
  insert(1 , &start1 , &finish1);
  insert(3 , &start1 , &finish1);
  insert(5 , &start1 , &finish1);
  insert(7 , &start1 , &finish1);
  insert(9 , &start1 , &finish1);
  display(start1);

  insert(2 , &start2 , &finish2);
  insert(4 , &start2 , &finish2);
  insert(6 , &start2 , &finish2);
  insert(8 , &start2 , &finish2);
  insert(10 , &start2 , &finish2);
  display(start2);

  start1 = mergeList(start1 , start2);
  display(start1);
  return 0;
}
