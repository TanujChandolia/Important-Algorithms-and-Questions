#include <iostream>
#include <string>
using namespace std;

int stack[50];
int top = -1;

void push(int x)
{
  top++;
  stack[top] = x;
}

int pop()
{
  int x = top;
  top--;
  return stack[x];
}

void display()
{
  for(int i = 0; i <= top; i++)
      cout<<stack[i]<<" ";
  cout<<endl;
}

void evaluationPostfix(string s)
{

  for(int  i = 0; i < s.length(); i++)
    {
        if(isdigit(s[i]))
          {
            push(s[i] - '0');
          }

        if(s[i] == '+')
            {
              push( pop() + pop() );
            }
        if(s[i] == '-')
            {
              int x = pop();
              push(pop() - x);
            }
        if(s[i] == '*')
            push(pop() * pop());
        if(s[i] == '/')
            {
              int x = pop();
              push(pop()/x);
            }

    }

    cout<<pop();
}

int main()
{
  string str = "231*+9-";
  evaluationPostfix(str);
  return 0;
}
