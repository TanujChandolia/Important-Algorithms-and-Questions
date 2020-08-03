#include<iostream>

using namespace std;
void swap(int arr[], int l , int h)
{
   int temp = arr[l];
   arr[l] = arr[h];
   arr[h] = temp;
}
void sorted(int arr[]  ,int n)
{
   int low = 0 , mid = 0 , high = n-1;
   while(mid <= high)
   {
      switch(arr[mid])
      {
         case 0: swap(arr, low++ , mid++);break;
         case 1: mid++; break;
         case 2: swap(arr, mid , high--);break;
      }
   }

   for(int  i = 0; i < n; i++)
      cout<<arr[i]<<" ";
   cout<<endl;
}
int main()
{
   int arr[] = {0,2,2,1,1,2,0,0,2};
   sorted(arr , sizeof(arr)/sizeof(arr[0]));
}
