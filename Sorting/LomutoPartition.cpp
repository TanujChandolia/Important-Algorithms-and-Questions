#include<iostream>
using namespace std;
void partition(int arr[] , int n ,int p)
{
   int temp;

   temp = arr[p];
   arr[p] = arr[n-1];
   arr[n-1] = temp;

   int pivot = arr[n-1];
   int l = 0 , h = n - 1;
   int i = -1;
   for(int j = l; j < h; j++)
   {
      if(arr[j] <= pivot)
         {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
   }

   temp = arr[i+1];
   arr[i+1] = arr[n-1];
   arr[n-1] = temp;

   for(int j = 0; j < n; j++)
      cout<<arr[j]<<" ";
}
int main()
{
   int arr[] = {3,7,8,15,12,20,9,10};
   int p = 4;
   partition(arr , sizeof(arr)/sizeof(arr[0]),  p );
   return 0;
}
