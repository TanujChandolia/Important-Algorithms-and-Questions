#include<iostream>
#include <cstring>
using namespace std;

char stack[50];
int top = -1;

void push(char x)
{
  top ++;
  stack[top] = x;
}

void pop()
{
  top --;
}

void check(string str)
{
  int flag = 0;
  for(int i = 0; i < str.length() ;i++)
  {
    if(str[i] == ')' && top == -1)
        {flag = 1; break;}
    if(str[i] == '(')
        push('(');
    if(str[i] == ')')
        pop();
  }

  if(top != -1)
      flag = 1;

  cout<<flag;
}

int main()
{
  string str = "((())())()";
  check(str);
  return 0;
}
