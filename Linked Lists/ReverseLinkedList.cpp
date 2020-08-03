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

void insertAtend(int val , node** head, node**tail){
   node* temp = new node(val);
   if(*head == nullptr)
      *head = *tail = temp;
   else{
      node* t = *tail;
      t -> next = temp;
      *tail = temp;
   }
}

void printList(node* head){
   while(head){
      cout<<head -> val<<" ";
      head = head -> next;
   }
   cout<<"\n";
}
node* recursiveReverseList(node* head){
   if(head == nullptr || head-> next == nullptr)
      return head;
   node* rec_head = recursiveReverseList(head-> next);
   node* rec_tail = head -> next;
   rec_tail -> next = head;
   head -> next = nullptr;
   return rec_head;
}
void reverseList(node** head, node** tail){
   if(*head == nullptr)
      return;

   node* before = nullptr;
   node* current = *head;
   node* after;
   while(current){
      after = current -> next;
      current -> next = before;
      before = current;
      current = after;
   }

   node* temp = *head;
   *head = *tail;
   *tail = temp;
}
int main(){
   node* head = nullptr;
   node* tail = nullptr;
   insertAtend(10,&head,&tail);
   insertAtend(20,&head,&tail);
   insertAtend(40,&head,&tail);
   insertAtend(80,&head,&tail);
   insertAtend(100,&head,&tail);
   printList(head);

   head = recursiveReverseList(head);

   printList(head);
}
