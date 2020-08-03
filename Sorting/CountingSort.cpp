#include<iostream>
using namespace std;

void CountingSort(int arr[] , int size , int max)
{
   int count[max + 1] = {0};
   int output[size];

   for(int i = 0; i < size; i++)
      count[arr[i]]++;
   for(int i = 1; i < max + 1; i++)
      count[i] += count[i-1];
   for(int i = size - 1; i >= 0; i--)
      {
         output[count[arr[i]] - 1] = arr[i];
         count[arr[i]]--;
      }
   for(int i = 0; i < size; i++)
         arr[i] = output[i];

   for(int i = 0; i < size; i++)
      cout<<arr[i]<<" ";
}



int main(){
  int arr[] = {2,9,5,6,7,8};
  int n  = sizeof(arr)/sizeof(arr[0]);
  int max = arr[0];
  for(int i = 1; i < n; i++)
      if(arr[i] > max)
            max = arr[i];
  CountingSort(arr,n,max);
  return 0;
}
