#include <iostream>
using namespace std;

int EmptyStack(int top)
{
  if(top == -1)
    return 1;
  return 0;
}

int FullStack(int top , int size)
{
  if(top == size - 1)
    return 1;
  return 0;
}

void PushStack(int stack[] , int &top , int value,int size)
{
  if(FullStack(top , size))
    cout<<endl<<"Stack is Full."<<endl;
  else
  {
    top ++;
    stack[top] = value;
  }
}

void PopStack(int &top , int stack[])
{
  if(EmptyStack(top))
    cout<<endl<<"Stack is Empty."<<endl;
  else
  {
    cout<<endl<<"Value "<<stack[top]<<" is deleted."<<endl;
    top -- ;
  }
}

void PrintStack(int stack[] , int top)
{
  cout<<"\nThe Stack is: ";
  for(int i = 0; i <= top ; i++)
    cout<<stack[i]<<" ";
}
int main()
{
  const int size = 10;
  int stack[size]; int top = -1;



  cout<<"1. Push Value"<<endl;
  cout<<"2. Pop Value"<<endl;
  cout<<"3. Check if Stack is empty"<<endl;
  cout<<"4. Check if Stack is full"<<endl;
  cout<<"5. Print Stack"<<endl<<endl;
  cout<<"Enter Choice: ";
  int choice,value,i;
  cin >> choice;
  while(choice <= 5 && choice >= 1)
  {
    switch(choice)
    {
      case 1: cout<<"Enter value to be pushed into stack: ";
              cin >> value;
              PushStack(stack,top,value,size);
              break;

      case 2: PopStack(top ,stack);
              break;

      case 3: if(EmptyStack(top))
                cout<<"\nStack is Empty.\n";
              else
                cout<<"\nStack is not Empty.\n";
              break;
      case 4: if(FullStack(top,size))
                cout<<"\nStack is full.\n";
              else
                cout<<"\nStack is not full.\n";
              break;

      case 5: PrintStack(stack,top);
              break;
    }
    cout<<endl<<"Enter Choice: ";
    cin>>choice;

  }

  return 0;
}
