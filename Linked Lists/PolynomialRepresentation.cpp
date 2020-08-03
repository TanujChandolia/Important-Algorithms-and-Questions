#include <iostream>
using namespace std;

struct node
{
  int coeff;
  int exp;
  struct node* next;
}*startpoly1 = NULL, *finishpoly1 = NULL , *startpoly2 = NULL , *finishpoly2 = NULL;

void insert(int coeff , int exp , struct node **start , struct node **finish)
{
  struct node* temp;
  temp = new node();
  temp -> coeff = coeff;
  temp -> exp = exp;

  struct node *s , *f;
  s = *start;
  f = *finish;

  if(s == NULL)
  {
    *start = *finish = temp;
  }
  else
  {
      f -> next = temp;
      *finish = temp;
      f = temp;
      f -> next = NULL;
  }
}

void display(struct node* start)
{
  struct node* temp;
  temp = start;
  while(temp != NULL)
  {
    cout<<temp->coeff<<"x^"<<temp->exp<<" ";

    if(temp -> next != NULL && temp -> next ->coeff > 0)
        cout<<"+ ";

    temp = temp -> next;
  }
  cout<<endl;
}

int main()
{
  insert(10,9,&startpoly1,&finishpoly1);
  insert(7,7,&startpoly1,&finishpoly1);
  insert(8,4,&startpoly1,&finishpoly1);
  insert(-3,2,&startpoly1,&finishpoly1);
  insert(1,1,&startpoly1,&finishpoly1);
  insert(-1,0,&startpoly1,&finishpoly1);
  display(startpoly1);

  insert(7,8,&startpoly2,&finishpoly2);
  insert(9,7,&startpoly2,&finishpoly2);
  insert(6,2,&startpoly2,&finishpoly2);
  insert(-2,1,&startpoly2,&finishpoly2);

  display(startpoly2);


  return 0;
}
