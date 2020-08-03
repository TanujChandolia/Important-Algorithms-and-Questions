#include <iostream>
using namespace std;

const int size = 3;
struct Queue
{
  int A[size];
  int front , rear , isEmpty;
};

void insertQ(int val ,int &front ,int  &rear, int &isEmpty ,int size, int A[])
{
  if(front == -1 && rear== -1)
      front = rear = 0;

  if(isEmpty == 0)
    cout<<"Queue is full.\n";
  else
  {
    A[rear] = val;
    cout<<"inserted "<<val<<" at position "<<rear<<endl;
    rear ++;
    isEmpty = 2;
    if(rear == size)
    {
      rear = 0;
      if(rear == front)
          isEmpty = 0;
    }
  }
}


void deleteQ(int &front , int &rear ,int &isEmpty ,int A[])
{
    if(isEmpty == 1)
        {
          cout<<"Queue is Empty.\n";
        }
    else
    {
      cout<<"Deleted "<<A[front]<<" at "<<front<<endl;
      front++;
      isEmpty = 2;
      if(front == size)
          {
            front = 0;
            if(front == rear)
                  isEmpty = 1;
          }
    }


}

void display()
{

}
int main()
{
  struct Queue q;
  q.front = -1;
  q.rear = -1;
  q.isEmpty = 1;

  insertQ(5 , q.front , q.rear ,q.isEmpty ,size ,q.A);
  insertQ(6 , q.front , q.rear ,q.isEmpty ,size ,q.A);
  insertQ(7 , q.front , q.rear ,q.isEmpty ,size ,q.A);

  insertQ(7 , q.front , q.rear ,q.isEmpty ,size ,q.A);


  deleteQ(q.front , q.rear , q.isEmpty , q.A);
  deleteQ(q.front , q.rear , q.isEmpty , q.A);
  deleteQ(q.front , q.rear , q.isEmpty , q.A);

  deleteQ(q.front , q.rear , q.isEmpty , q.A);

  insertQ(2 , q.front , q.rear ,q.isEmpty ,size ,q.A);

  return 0;
}
