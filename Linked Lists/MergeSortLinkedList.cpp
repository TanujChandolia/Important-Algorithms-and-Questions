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
node* mergeList(node* a, node* b){
   if(a==nullptr)return b;
   if(b==nullptr)return a;
   node* result;
   if(a -> val <= b -> val){
      result = a;
      result -> next = mergeList(a -> next, b);
   }
   else{
      result = b;
      result -> next = mergeList(a, b -> next);
   }
   return result;
}
void SplitList(node* head, node** front, node** back){
   node* slow = head;
   node* fast = head -> next;
   while(fast && fast -> next){
      slow = slow-> next;
      fast = fast -> next;
   }
   *front = head;
   *back = slow -> next;
   slow -> next = nullptr;
}

node* mergeSort(node* head){
   node* a;
   node* b;
   if(head == nullptr || head -> next == nullptr)
      return head;
   SplitList(head,&a,&b);
   a = mergeSort(a);
   b = mergeSort(b);
   head = mergeList(a,b);
   return head;
}
int main(){
   node* head = nullptr;
   node* tail = nullptr;

   insertAtend(2 , &head, &tail);
   insertAtend(10 , &head, &tail);
   insertAtend(5, &head, &tail);
   insertAtend(8 , &head, &tail);
   insertAtend(3 , &head, &tail);
   insertAtend(1 , &head, &tail);
   insertAtend(9 , &head, &tail);
   printList(head);

   head = mergeSort(head);
   printList(head);
}
