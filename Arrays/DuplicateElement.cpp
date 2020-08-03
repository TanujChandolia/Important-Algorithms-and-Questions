#include<iostream>
using namespace std;

int findDuplicate(int arr[] , int n){
   int slow = arr[0];
   int fast = arr[0];

   while(true){
      slow = arr[slow];
      fast = arr[arr[fast]];
      if(slow == fast)
         break;
   }

   slow = arr[0];
   while(slow != fast){
      slow = arr[slow];
      fast = arr[fast];
   }
   return slow;
}
int main(){
   int arr[] = {3,1,3,4,2};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout<<findDuplicate(arr , n);
}
