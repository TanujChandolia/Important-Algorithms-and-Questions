#include<iostream>
using namespace std;

class Stack{
   int* arr;
   int* next;
   int* top;

   int cap , k;
   int free;

public:
   Stack(int capacity , int kstacks){
      cap = capacity;
      k = kstacks;
      arr = new int[cap];
      next = new int[cap];
      top = new int[k];
      free = 0;
      for(int i = 0; i < cap; i++)
         arr[i] = 0;
      for(int i = 0; i < k; i++)
         top[i] = -1;
      for(int i = 0; i < cap - 1; i++)
         next[i] = i+1;
      next[cap-1] = -1;
   }
   bool isFull(){return (free == -1);}
   bool isEmpty(int sn){return (top[sn] == -1);}
   void push(int x, int sn);
   int pop(int sn);

   void display(int sn){
      int t = top[sn];
      while(t != -1){
         cout<<arr[t]<<" ";
         t = next[t];
      }
      cout<<endl;
   }
};

void Stack::push(int x, int sn){
   if(isFull()){
      cout<<"Stack Overflow\n";
   }
   else{
      int i = free;
      free = next[i];
      next[i] = top[sn];
      top[sn] = i;
      arr[i] = x;
   }
}
int Stack::pop(int sn){
   if(isEmpty(sn)){
      cout<<"Stack Underflow\n";
      return -1;
   }
   else{
      int i = top[sn];
      top[sn] = next[i];
      next[i] = free;
      free  = i;
      return arr[i];
   }
}

int main(){
   Stack st(10 , 3);
   st.push(5,0);
   st.push(10,0);
   st.push(15,0);
   st.push(3,1);
   st.push(6,1);
   st.push(9,1);
   st.pop(0);
   st.pop(1);
   st.display(1);
}
