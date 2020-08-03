#include<iostream>
using namespace std;
int lpart(int arr[] , int l , int h)
{
   int pivot = arr[h];
   int i = l - 1;
   for(int j = l; j < h; j++)
   {
      if(arr[j] <= pivot)
         {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
   }

   int temp = arr[i + 1];
   arr[i + 1] = arr[h];
   arr[h] = temp;
   return (i + 1);
}
void qSort(int arr[] , int l , int h)
{
   if(l < h)
   {
      int p = lpart(arr , l , h);
      qSort(arr , l ,p - 1);
      qSort(arr, p + 1 , h);
   }
}
int main()
{
   int arr[] = {8,4,7,9,3,10,5};
   int n = sizeof(arr)/sizeof(arr[0]);
   qSort(arr , 0 ,n - 1);
   for(int i = 0; i < n; i++)
      cout<<arr[i]<<" ";
}
