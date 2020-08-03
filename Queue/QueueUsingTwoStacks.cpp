#include<iostream>
using namespace std;

int stack1[10] ,stack2[10];
int top1 = -1, top2 = -1;

void enqueue(int x)
{
    top1++;
    stack1[top1] = x;
    cout<<x<<" is pushed.\n";
}

int dequeue()
{
  if(top1 == -1 && top2 == -1)
      cout<<"Queue is Empty.";
  else
    {
      if(top2 == -1)
        {
          while(top1 != -1)
          {
            top2 ++;
            stack2[top2] = stack1[top1];
            top1--;
          }
        }
    }

    int x = stack2[top2];
    top2 -- ;
    return x;
}

int main()
{
  enqueue(1);
  enqueue(3);
  enqueue(5);
  int x = dequeue(); cout<<x<<" is removed\n";
  x = dequeue(); cout<<x<<" is removed\n";

  return 0;
}
