#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
void CountingSort(int arr[] , int n , int exp)
{
   int count[10] = {0};
   int output[n];
   for(int i = 0; i < n; i++) count[(arr[i]/exp)%10] ++;
   for(int i = 1; i < 10; i++) count[i] += count[i-1];

   for(int i = n - 1; i >= 0; i--)
      {
         output[count[(arr[i]/exp)%10] - 1] = arr[i];
         count[(arr[i]/exp)%10]--;
      }
   for(int i = 0; i < n; i++) arr[i] = output[i];

}
void RadixSort(int arr[] , int n)
{
   int mx = arr[0];
   for(int i = 1; i < n; i++)
      if(arr[i] > mx)
         mx = arr[i];

   for(int exp = 1; mx/exp > 0; exp = exp * 10)
      {
         CountingSort(arr , n , exp);
      }
}
int main()
{
   int arr[] = {319,212,6,8,100,50};
   int n = sizeof(arr)/sizeof(arr[0]);

   RadixSort(arr , n);
   for(int i = 0; i < n; i++)
      cout<<arr[i]<<" ";
}
