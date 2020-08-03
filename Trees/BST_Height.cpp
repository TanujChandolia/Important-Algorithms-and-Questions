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

int calcHeight(node* root)
{
   if(root == nullptr)
      return 0;

   int leftH = 0 , rightH = 0;
   node* temp = root;
   if(temp -> left != nullptr)
      leftH = 1 + calcHeight(temp -> left);
   if(temp -> right != nullptr)
      rightH = 1 + calcHeight(temp -> right);
   return (leftH > rightH ? leftH : rightH);
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

   cout<<"\nHeight of the given tree is: "<<calcHeight(root)<<endl;
   return 0;
}
