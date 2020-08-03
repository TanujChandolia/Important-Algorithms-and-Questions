#include<iostream>
using namespace std;
struct node{
   int val;
   node* next;
   node(int x){
      val = x;
      next = nullptr;
   }
};

void insertAtend(int value , node** head , node** tail){
   node* temp = new node(value);

   if(*head == nullptr){
      *head = *tail = temp;
   }
   else{
      node* t = *tail;
      t -> next = temp;
      *tail = temp;
   }
}

void printList(node* head){
   while(head != nullptr){
      cout<<head -> val<<" ";
      head = head -> next;
   }
   cout<<endl;
}

node* swapKthNode(node* head, int num , int k){
   if(head == nullptr || k > num)
      return head;
   if(2*k - 1 == num)
      return head;
   node* node1 = head;
   node* node2 = head;
   node* prev1 = nullptr;
   node* prev2 = nullptr;

   for(int i = 1; i < k; i++){
      prev1 = node1;
      node1 = node1 -> next;
   }
   for(int i = 1; i < num-k+1; i++){
      prev2 = node2;
      node2 = node2 -> next;
   }

   if(prev1)
      prev1 -> next = node2;
   if(prev2)
      prev2 -> next = node1;

   node* temp = node1 -> next;
   node1 -> next = node2 -> next;
   node2 -> next = temp;

   if(k == 1)
      return node2;
   if(k == num)
      return node1;
   return head;
}
int main(){
   node* head = nullptr;
   node* tail = nullptr;

   insertAtend(10 , &head, &tail);
   insertAtend(20 , &head, &tail);
   insertAtend(30 , &head, &tail);
   insertAtend(40 , &head, &tail);
   insertAtend(50 , &head, &tail);
   insertAtend(60 , &head, &tail);
   printList(head);

   head = swapKthNode(head , 6 , 1);
   printList(head);
}
