#include <iostream>
using namespace std;

struct node
{
  int data;
  struct node *next;
};
struct node *top;


void pushStack(int val)
{
  struct node *temp;
  temp = new node();

  temp -> data = val;
  temp -> next = top;
  top = temp;
}

void popStack()
{
  if(top == NULL)
    {
      cout<<"Stack is Empty."<<endl;
    }
  else
  {
    struct node* temp;
    temp = top;
    cout<<"Value "<<top -> data<<" is deleted."<<endl;
    top = top -> next;
    temp -> next = NULL;
    free(temp);

  }

}

void displayStack()
{
  if(top == NULL)
  {
    cout<<"Stack is Empty."<<endl;
  }

  else
  {
    struct node* temp;
    temp = top;
    while(temp != NULL)
    {
      cout<<temp -> data<<" ";
      temp = temp -> next;
    }
  }
}


int main()
{
  cout<<"Insert Value."<<endl;
  cout<<"Delete Value."<<endl;
  cout<<"Print Stack."<<endl<<endl;
  cout<<"Enter Choice: ";

  int choice;
  cin>>choice;

  while(choice >= 1 && choice <= 3)
  {
    switch (choice)
    {
      case 1: cout<<"Enter Value to be inserted: ";
              int val;cin>>val;
              pushStack(val);
              break;

      case 2: popStack();
              break;

      case 3: displayStack();

    }

    cout<<endl<<"Enter Choice: "; cin>>choice;
  }
  return 0;
}
