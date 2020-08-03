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


void preOrder(node* root)
{
   node* temp = root;
   cout<<temp -> data<<" ";
   if(temp -> left != nullptr)
      preOrder(temp -> left);
   if(temp -> right != nullptr)
      preOrder(temp -> right);
}

void inOrder(node* root)
{
   node* temp = root;
   if(temp -> left != nullptr)
      inOrder(temp -> left);
   cout<<temp -> data<<" ";
   if(temp -> right!= nullptr)
      inOrder(temp -> right);
}

void postOrder(node* root)
{
   node* temp = root;
   if(temp -> left != nullptr)
      postOrder(temp -> left);
   if(temp -> right != nullptr)
      postOrder(temp -> right);
   cout<<temp -> data<<" ";
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

   cout<<"\n\nWhat type of traversal would you like to see?\n";
   cout<<"1) PreOrder\n";
   cout<<"2) InOrder\n";
   cout<<"3) PostOrder\n";
   cout<<"Enter Choice: ";int choice; cin>>choice;

   switch(choice)
   {
      case 1: cout<<"PreOrder: ";preOrder(root); break;
      case 2: cout<<"InOrder: ";inOrder(root); break;
      case 3: cout<<"PostOrder: ";postOrder(root); break;

      default:"\nInvalid input.Exiting.";exit(1);
   }
   return 0;
}
