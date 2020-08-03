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


void deleteVal(int val)
{
   node* par = nullptr, *cur = root, *child;
   if(root == nullptr)
      {
         cout<<"Empty Tree\n";
         return;
      }

   while(cur != nullptr)
      {
         if(cur -> data == val)
            {
               break;
            }
         if(val < cur -> data)
            {
               par = cur;
               cur = cur -> left;
            }
         else
            {
               par = cur;
               cur = cur -> right;
            }
      }

   if(par != nullptr)
      cout<<"\nParent data: "<<par -> data<<endl;
   cout<<"Location data: "<<cur -> data<<endl;

   if(cur -> left == nullptr || cur -> right == nullptr)
   {
      if(cur -> left == nullptr && cur -> right == nullptr)
         child = nullptr;
      else if(cur -> left != nullptr && cur -> right == nullptr)
         child = cur -> left;
      else if(cur -> left == nullptr && cur -> right != nullptr)
         child = cur-> right;

      if(par != nullptr)
            {
               if(cur == par -> left)
                  {
                     par -> left = child;
                     cout<<"Deleted "<<cur -> data<<". "<<par -> data<<" now points to ";
                     if(child == nullptr)
                        cout<<"null\n";
                     else
                        cout<<par -> left -> data<<endl;
                  }
               else
                  {
                     par -> right = child;
                     cout<<"Deleted "<<cur -> data<<". "<<par -> data<<" now points to ";
                     if(child == nullptr)
                        cout<<"null\n";
                     else
                        cout<<par-> right -> data<<endl;
                  }
               free(cur);
            }
      else
         {
            root = child;
            cout<<"Deleted "<<cur-> data<<". New value of root is "<<root-> data<<endl;
         }
   }

   else
      {
         node* ptr = cur -> right;
         node* save = cur;
         while(ptr -> left != nullptr)
            {
               save = ptr;
               ptr = ptr -> left;
            }

         node* suc = ptr;
         node* parsuc = save;

         parsuc -> left = suc -> right;
         cout<<parsuc -> data<<" now points to ";
         if(parsuc -> left == nullptr)
            cout<<"null\n";
         else
            cout<<parsuc -> left ->data<<endl;
         if(par != nullptr)
            {
               if(cur == par -> left)
                  {
                     par -> left = suc;
                     cout<<cur -> data<<"  Deleted. "<<par -> data<<" now points to "<<par->left-> data<<endl;
                  }
               else
                  {
                     par -> right = suc;
                     cout<<cur -> data<<" Deleted. "<<par -> data<<" now points to "<<par->right-> data<<endl;
                  }
            }
         else
            {
               root = suc;
            }
         suc -> left = cur -> left;
         cout<<suc -> data<<" now points to on left "<<suc -> left->data<<endl;
         suc -> right = cur -> right;
         cout<<suc ->data<<" now points to on right "<<suc -> right->data<<endl;
         free(cur);
      }
}

int main()
{
   cout<<"How many values would you like to enter in the tree? : ";
   int num; cin>>num;int val;
   for(int i = 0; i < num; i++)
      {
         cin>> val;
         insert(val);
      }

   cout<<"\nEnter the value to be deleted: ";
   cin>>val; deleteVal(val);
   return 0;
}
