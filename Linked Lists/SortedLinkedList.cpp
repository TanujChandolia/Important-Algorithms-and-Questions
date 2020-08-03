#include<iostream>
using namespace std;

struct node
{
   int data;
   node* next;
}*start = nullptr , *finish = nullptr;

void insert(int val)
{
   node*temp = new node;
   temp -> data = val;
   temp -> next = nullptr;

   if(start == nullptr)
      start = finish = temp;
   else
      {
         if(val < start -> data)
            {
               temp -> next = start;
               start = temp;
            }
         else if(val > finish -> data)
            {
               finish -> next = temp;
               finish = temp;
            }
         else
            {
               node* ptr = start;
               while(ptr -> next ->data < val)
                  ptr = ptr -> next;
               temp -> next = ptr -> next;
               ptr -> next = temp;
            }
      }
}

void del(int val)
{
   if(val == start -> data)
   {
      node* ptr = start;
      start = start -> next;
      free(ptr);
   }

   else
   {
      node* ptr = start;
      while(ptr -> next -> data != val)
         ptr = ptr -> next;
      node* save = ptr -> next;
      ptr -> next = ptr -> next -> next;
      free(save);
   }
}
void display()
{
   cout<<"Linked List: ";
   node* temp = start;
   while(temp)
      {
         cout<< temp -> data<<" ";
         temp = temp -> next;
      }
   cout<<endl;
}
int main()
{
   cout<<"Insert Values: \n";
   for(int i = 0 ; i < 5; i++)
      {
         int val;
         cin>>val;
         insert(val);
         display();
      }
   cout<<"\nDelete Values: \n";
   for(int i = 0 ; i < 2; i++)
      {
         int val;
         cin>> val;
         del(val);
         display();
      }
   return 0;
}
