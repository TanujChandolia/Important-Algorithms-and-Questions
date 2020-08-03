#include<iostream>
#include<ctime>
using namespace std;
int lpart(int arr[] , int l , int r)
{
   int pivot = arr[r];
   int i = l-1;
   for(int j = l;j < r; j++)
   {
      if(arr[j] <= pivot)
         {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
   }
   arr[r] = arr[i+1];
   arr[i+1] = pivot;
   return (i+1);
}
int rpart(int arr[] , int l , int r)
{
   srand(time(0));
   int n = r - l + 1;
   int pivot = rand() % n;

   int temp = arr[pivot + l];
   arr[pivot + l] = arr[r];
   arr[r] = temp;

   return lpart(arr , l , r);
}
int smallest(int arr[] , int l , int r , int k)
{
   while(l <= r)
   {
      int p = rpart(arr , l , r);
      if(p == k - 1)
         return arr[p];
      if(p > k-1)
         r = p - 1;
      else
         l = p + 1;
   }
   return -1;
}
int main()
{
   int arr[] = {12,5,787,1,23};
   int n = sizeof(arr)/sizeof(arr[0]);
   int k = 2;

   cout<<smallest(arr , 0 , n - 1, k);
}
