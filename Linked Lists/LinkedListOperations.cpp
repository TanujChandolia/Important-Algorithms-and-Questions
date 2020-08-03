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

void insertAtstart(int value, node** head , node** tail){
   node* temp = new node(value);

   if(*head == nullptr){
      *head = *tail = temp;
   }
   else{
      temp -> next = *head;
      *head = temp;
   }
}

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
}
int main(){
   node* head = nullptr;
   node* tail = nullptr;

   insertAtstart(10 , &head , &tail);
   insertAtstart(20 , &head , &tail);
   insertAtend(5 , &head, &tail);
   printList(head);
}
