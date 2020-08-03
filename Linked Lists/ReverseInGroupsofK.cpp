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
void insertAtend(int val, node** head, node** tail){
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
   cout<<endl;
}

node* Recursive_reverseInGroups(node* head, int k ){
   if(head == nullptr)
      return head;
   node* curr = head;
   node* before = nullptr, *after = nullptr;
   int count = k;

   while(count-- && curr != nullptr){
      after = curr -> next;
      curr -> next = before;
      before = curr;
      curr = after;
   }
   head -> next = Recursive_reverseInGroups(curr , k);
   return before;
}

node* Iterative_reverseIngroups(node* head, int k){
   if(head == nullptr)
      return head;

   node* current = head;
   node* before = nullptr, *after = nullptr, *prevFirst = nullptr;
   bool isfirstpass = true;
   int count;

   while(current){
      node* first = current;
      before = nullptr;
      count = k;
      while(count-- && current != nullptr){
         after = current -> next;
         current -> next = before;
         before = current;
         current = after;
      }
      if(isfirstpass){
         head = before;
         isfirstpass = false;
      }
      else{
         prevFirst -> next = before;
      }
      prevFirst = first;
   }

   return head;
}

int main(){
   node* head = nullptr;
   node* tail = nullptr;

   insertAtend(1,&head,&tail);
   insertAtend(2,&head,&tail);
   insertAtend(2,&head,&tail);
   insertAtend(4,&head,&tail);
   insertAtend(5,&head,&tail);
   insertAtend(6,&head,&tail);
   insertAtend(7,&head,&tail);
   insertAtend(8,&head,&tail);
   printList(head);

   head = Iterative_reverseIngroups(head,2);

   printList(head);
}
