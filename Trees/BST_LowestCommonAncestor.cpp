#include<iostream>
using namespace std;

struct node
{
   int data;
   node* left;
   node* right;
}*root = nullptr;

void insert(int val)
{
   node* temp = new node;
   temp -> left = nullptr;
   temp -> right = nullptr;
   temp -> data = val;

   if(root == nullptr)
      {
         root = temp;
         cout<<"Value inserted at root\n";
      }
   else
      {
         node* ptr = root;
         while(ptr)
            {
               if(ptr -> data > val)
                  {
                     if(ptr -> left == nullptr)
                        {
                           ptr -> left = temp;
                           cout<<"Value inserted at left of "<<ptr -> data<<endl;
                           break;
                        }
                     else
                        ptr = ptr -> left;
                  }
               if(ptr -> data < val)
                  {
                     if(ptr -> right== nullptr)
                        {
                           ptr -> right = temp;
                           cout<<"Value inserted at right of "<<ptr -> data<<endl;
                           break;
                        }
                     else
                        ptr = ptr -> right;
                  }
            }
      }
}
void lca(node* root , int v1 , int v2)
   {
      node* ptr = root;
      while(ptr != nullptr)
         {
            if(ptr -> data < v1 && ptr -> data < v2)
               ptr = ptr -> right;
            else if(ptr -> data > v1 && ptr -> data > v2)
               ptr = ptr -> left;
            else
               break;
         }
      cout<<"\nThe Lowest Common Ancestor is: "<<ptr -> data<<endl;
   }

int main()
{
   cout<<"How many values would you like to enter in the tree? : ";
   int num; cin>>num;
   for(int i = 0; i < num; i++)
      {
         int val;
         cin>> val;
         insert(val);
      }

   cout<<"\nEnter the two elements of whose common ancestor you need to find out:\n";
   int v1 , v2;
   cin>> v1 >> v2;
   lca(root , v1 , v2);
   return 0;
}
