#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node* next;
}*front = NULL , *rear = NULL;

void InsertQ(int val)
{
      struct Node* temp;
      temp = new Node();
      temp -> data = val;

      if(front == NULL)
      {
        front = rear = temp;
      }

      else
      {
        rear -> next = temp;
        rear = temp;
      }
}


void DeleteQ()
{
      if(front == NULL)
      {
        cout<<"Queue is Empty.\n";
      }

      else
      {
        struct Node* temp;
        temp = front;
        cout<<"Value "<<front -> data<<" is deleted.\n";
        front = front -> next;
        free(temp);
      }
}

void DisplayQ()
{
      struct Node* temp;
      if(front == NULL)
      {
        cout<<"Queue is Empty\n";
      }

      else
      {
        temp = front;
        while(temp != NULL)
        {
          cout<<temp -> data<<" ";
          temp = temp -> next;
        }
      }
}

int main()
{
  cout<<"1) Insert Value into Queue.\n";
  cout<<"2) Delete Value from Queue.\n";
  cout<<"3) Print Queue.\n\n";
  cout<<"Enter Choice: ";
  int choice; cin >>choice;

  while(choice <= 3 && choice > 0){

    switch(choice){

      case 1: cout<<"Insert the value to be inserted: "; int val; cin >> val;
              InsertQ(val);
              break;

      case 2: DeleteQ();
              break;

      case 3: DisplayQ();
              break;
    }

    cout<<"\nEnter Choice: "; cin>>choice;
  }
  return 0;
}
