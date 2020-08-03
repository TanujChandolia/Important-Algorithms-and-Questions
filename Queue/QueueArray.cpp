#include<bits/stdc++.h>
using namespace std;

class Queue{
   int *arr;
   int size;
   int front;
   int rear;
public:
   Queue(int n){
      size = n;
      arr = new int[size];
      front = rear = 0;
   }

   void push(int x);
   int pop();
};

void Queue::push(int x){
   if(rear == size - 1){
      cout<<"Queue Overflow\n";
      return;
   }
   arr[rear] = x;
   rear++;
}

int Queue::pop(){
   if(front == rear){
      cout<<"Queue Underflow\n";
      return -1;
   }
   int x = arr[front];
   front++;
   return x;
}
int main(){
   Queue q(10);
   q.push(10);
   q.push(20);
   q.push(30);
   q.push(40);
   cout<<q.pop();
   return 0;
}
