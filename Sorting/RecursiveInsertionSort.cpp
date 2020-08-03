#include<iostream>
using namespace std;

void insSort(int arr[] , int start , int end)
{
   if(start == end)
      return;
   insSort(arr , start , --end);
   int temp = arr[end];
   int ptr = end - 1;
   while(ptr >= 0 && arr[ptr] > temp)
   {
      arr[ptr+1] = arr[ptr];
      ptr--;
   }
   arr[ptr + 1] = temp;
}
int main()
{
   int arr[] = {15,7,4,8,3,9,2};
   int n = sizeof(arr)/sizeof(arr[0]);
   insSort(arr , 0 , n);

   for(int i:arr)
      cout<<i<<" ";
}
