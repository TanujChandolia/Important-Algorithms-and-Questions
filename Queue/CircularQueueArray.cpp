#include <iostream>
using namespace std;
const int size = 5;
int queue[size];
int front = -1;
int rear = -1;

int isEmpty(int f , int r)
{
  if(f == r)
    return 1;
  return 0;
}

int isFull(int f , int r)
{
  if(r + 1 == f)
      return 1;
   return 0;
}
void insertQ(int val)
{
    if(front == -1 && rear == -1)
        front = rear = 0;

    if(rear == size - 1)
        rear = -1;

    if(isFull(front, rear))
        cout<<"\nQueue is full. Cannot insert "<<val<<endl;
    else
    {
      rear ++;
      queue[rear] = val;
      cout<<"Value "<<val<<" inserted at position "<<rear <<endl;
    }
}

void deleteQ()
{
    if(isEmpty(front,rear))
    {
      cout<<"\nQueue is empty. Cannot delete values further.\n";
    }
    else
    {
    cout<<"Value deleted is "<<queue[front+1]<<" at position "<<front+1<<endl;
    front ++ ;
    }

    if(front == size - 1)
      front = -1;
}

void display()
{
    for(int i = front + 1; i <= rear; i++)
    {
      cout<<queue[i]<<" ";
    }
}

int main()
{
  insertQ(1);
  insertQ(2);
  insertQ(3);
  insertQ(4);
  insertQ(5);

  deleteQ();

  insertQ(5);

  deleteQ();
  deleteQ();
  deleteQ();
  deleteQ();
  deleteQ();

  insertQ(6);
  insertQ(7);

  display();
  return 0;
}
