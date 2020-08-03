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

int nodes = 0;
void leafNodes(node* root)
{
   node* temp = root;
   if(temp -> left == nullptr && temp -> right == nullptr)
      nodes++;
   if(temp -> left != nullptr)
      leafNodes(temp -> left);
   if(temp -> right != nullptr)
      leafNodes(temp -> right);

}
int Tnodes = 0;
void totalNodes(node* root)
{
   node* temp = root;
   if(root != nullptr && Tnodes == 0)
      Tnodes++;
   if(temp -> left != nullptr)
      {
         Tnodes++;
         totalNodes(temp -> left);
      }
   if(temp ->right != nullptr)
      {
         Tnodes ++;
         totalNodes(temp -> right);
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

   cout<<"PreOrder: ";preOrder(root);
   cout<<"\nInOrder: ";inOrder(root);
   cout<<"\nPostOrder: ";postOrder(root);
   cout<<"\nNo. of Leaf Nodes: ";leafNodes(root);cout<<nodes;
   cout<<"\nTotal No. of Nodes: ";totalNodes(root);cout<<Tnodes;
   cout<<"\nHeight of the Tree: "<<calcHeight(root);

   return 0;
}
