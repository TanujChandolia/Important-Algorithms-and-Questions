#include<iostream>
#include<queue>
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


void levelOrder(node* root)
{
   node* temp = root;
   queue<node*> q;

   if(root != nullptr)
      q.push(root);

   while(!q.empty())
   {
      cout<<temp -> data<<" ";
      if(temp -> left != nullptr)
         q.push(temp -> left);
      if(temp -> right != nullptr)
         q.push(temp -> right);
      q.pop();
      temp = q.front();
   }
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

   cout<<"\nThe Level Order Traversal is: " ;
   levelOrder(root);
   return 0;
}
