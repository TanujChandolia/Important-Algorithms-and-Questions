#include<iostream>

using namespace std;
int HoarePart(int arr[] , int l , int h)
{
   int pivot = arr[l];
   int i = l - 1;
   int j = h + 1;
   while(true)
   {
      do{
         i++;
      }while(arr[i] < pivot);
      do{
         j--;
      }while(arr[j] > pivot);

      if(i >= j)
         return j;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
   }
}
void qSort(int arr[] , int l , int h)
{
   if(l < h)
   {
      int p = HoarePart(arr,l,h);
      qSort(arr , l , p);
      qSort(arr , p + 1 , h);
   }
}
int main()
{
   int arr[] = {8,4,7,9,3,10,5};
   int n = sizeof(arr)/sizeof(arr[0]);
   qSort(arr , 0 , n - 1);
   for(int i = 0; i < n; i++)
      cout<<arr[i]<<" ";
}
