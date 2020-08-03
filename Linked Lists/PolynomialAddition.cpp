#include <iostream>
using namespace std;

struct node
{
  int coeff, exp;
  struct node* next;
}*startpoly1 = NULL, *startpoly2 = NULL, *finishpoly1 = NULL, *finishpoly2 = NULL, *startpoly = NULL , *finishpoly = NULL;

void insert(int coeff, int exp , struct node** start , struct node**finish)
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
    f = temp;
    *finish = temp;
    f -> next = NULL;
  }
}

void add(struct node* start1 , struct node* start2)
{
  struct node* temp1 , *temp2;
  temp1 = start1;
  temp2 = start2;

  while(temp1 != NULL && temp2 != NULL)
  {
    if(temp1 -> exp == temp2 -> exp)
      {
        insert(temp1 -> coeff + temp2 ->coeff , temp1 -> exp , &startpoly , &finishpoly);
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
      }

    else if(temp1 -> exp > temp2 -> exp)
      {
        insert(temp1 -> coeff, temp1 -> exp, &startpoly, &finishpoly);
        temp1 = temp1 -> next;
      }

    else
      {
        insert(temp2 -> coeff , temp2 -> exp , &startpoly,&finishpoly);
        temp2 = temp2 -> next;
      }

  }

  while(temp1 != NULL)
  {
    insert(temp1 -> coeff, temp1 -> exp , &startpoly,&finishpoly);
    temp1 = temp1 -> next;
  }

  while(temp2 != NULL)
  {
    insert(temp2 ->coeff , temp2 -> exp ,&startpoly , &finishpoly);
    temp2 = temp2 -> next;
  }

}


void display(struct node* start)
{
  struct node *temp;
  temp = start;

  while(temp!=NULL)
  {
    cout<<temp -> coeff<<"x^"<<temp -> exp<<" ";
    if (temp -> next != NULL && temp -> next ->coeff > 0)
          cout<<"+ ";
    temp = temp ->next;
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

  add(startpoly1 , startpoly2);
  cout<<endl<<"Addition: "<<endl;
  display(startpoly);

  return 0;
}
