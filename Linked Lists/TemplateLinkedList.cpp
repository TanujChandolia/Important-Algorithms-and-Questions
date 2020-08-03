#include<iostream>
#include<cstring>
using namespace std;

template <typename T>
class node
{
public:
  T data;
  node<T> *next;
};

template <typename T>
class LinkedList
{

public:
  node<T> *start , *finish;
  LinkedList() {start = NULL;finish = NULL;}

  void insert(T val)
    {
      node<T> *temp;
      temp = new node<T>;
      temp -> data = val;
      temp -> next = NULL;
      if(start == NULL)
        {
          start = temp;
          finish = temp;
        }
      else
        {
          finish -> next = temp;
          finish = temp;
          finish -> next = NULL;
        }
    }

  void display()
  {
    node<T> *temp = start;
    while(temp != NULL)
      {
        cout<< temp -> data<<" ";
        temp = temp -> next;
      }
  }
};

int main()
{
  LinkedList<int> L;
  L.insert(10);
  L.insert(15);
  L.insert(20);
  L.display();
  return 0;
}
