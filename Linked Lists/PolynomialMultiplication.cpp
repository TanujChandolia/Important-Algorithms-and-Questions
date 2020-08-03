#include <iostream>
using namespace std;

struct node
{
  int coeff , exp;
  struct node* next;
}*startpoly1 = NULL, *finishpoly1 = NULL, *startpoly2 = NULL,*finishpoly2 = NULL,*startpoly = NULL, *finishpoly = NULL;

void insert(int coeff , int exp , struct node** start, struct node**finish)
{
  struct node *temp;
  temp = new node();
  temp -> coeff = coeff;
  temp -> exp = exp;

  struct node* s, *f;
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


void display(struct node* start)
{
  struct node* temp;
  temp = start;
  while(temp != NULL)
  {
    cout<<temp -> coeff<<"x^"<<temp -> exp<<" ";
    if(temp -> next != NULL && temp -> next ->coeff > 0)
          cout<<"+ ";
    temp = temp -> next;
  }
  cout<<endl;
}

void insertAfter(int coeff , int exp , struct node **start, struct node**finish)
{
  struct node* temp;
  temp = new node();
  temp -> coeff = coeff;
  temp -> exp = exp;

  struct node* s, *f;
  s = *start;
  f = *finish;

  if(s == NULL)
  {
    *start = *finish = temp;
  }
  else
  {
    struct node* ptr, *save;
    ptr = s;
    while(ptr != NULL && temp != NULL)
    {
      if(temp -> exp == ptr -> exp )
      {
        ptr -> coeff = ptr -> coeff + temp -> coeff;
        temp = NULL;
        free(temp);
        break;
      }
      else if(temp -> exp < ptr -> exp)
          {
            save  = ptr;
            ptr = ptr -> next;
          }
      else
        {
          break;
        }
    }

    if(temp != NULL)
    {
      temp -> next = save -> next;
      save -> next = temp;

      if(temp -> next == NULL)
      {
        *finish = temp;
      }
    }
  }

}

void multiply(struct node*start1 , struct node* start2)
{
  struct node* temp1, *temp2;

  for(temp1 = start1 ; temp1 != NULL; temp1 = temp1 -> next)
  {
    for(temp2 = start2; temp2 != NULL; temp2 = temp2 -> next)
    {
      insertAfter(temp1 -> coeff * temp2 -> coeff , temp1 -> exp + temp2 -> exp, &startpoly,&finishpoly);
    }
  }
}




int main()
{
  insert(10,9,&startpoly1,&finishpoly1);
  insert(7,7,&startpoly1,&finishpoly1);
  insert(8,4,&startpoly1,&finishpoly1);
  insert(-3,2,&startpoly1,&finishpoly1);
  insert(1,1,&startpoly1,&finishpoly1);
  insert(-1,0,&startpoly1,&finishpoly1);
  cout<<"P1(x) = ";
  display(startpoly1);

  insert(7,8,&startpoly2,&finishpoly2);
  insert(9,7,&startpoly2,&finishpoly2);
  insert(6,2,&startpoly2,&finishpoly2);
  insert(-2,1,&startpoly2,&finishpoly2);

  cout<<"P2(x) = ";
  display(startpoly2);

  multiply(startpoly1,startpoly2);
  cout<<"\nMultiplication:\nP(x) = ";
  display(startpoly);

  return 0;
}
