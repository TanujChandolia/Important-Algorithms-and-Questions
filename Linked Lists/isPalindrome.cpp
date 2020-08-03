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
void reversell(node* startRev, node* last){
   if(startRev == last)
      return;
   node* curr = startRev;
   node* before = nullptr, *after = nullptr;
   while(curr){
      after = curr -> next;
      curr -> next = before;
      before = curr;
      curr = after;
   }
}
bool isPalindrome(node* head){
   node* first = head;
   node* last = head;
   int count = 1 , goThisTimes;
   while(last -> next){
      last = last -> next;
      count++;
   }

   if(count % 2 == 0)
      goThisTimes = count / 2;
   else
      goThisTimes = (count/2) + 1;

   node* startRev = head;
   for(int i = 1; i < goThisTimes; i++){
      startRev = startRev -> next;
   }
   reversell(startRev,last);

   while(first != last){
      cout<<first -> val<<" "<<last -> val<<endl;
      if(first -> val != last -> val)
         return  false;
      first = first -> next;
      last = last -> next;
   }
   return true;
}
int main(){
   node* head = nullptr;
   node* tail = nullptr;
   int val;
   for(int i = 0; i < 45; i++){
      cin >> val;
      insertAtend(val , &head, &tail);
   }
   printList(head);

   cout<<isPalindrome(head);
}
