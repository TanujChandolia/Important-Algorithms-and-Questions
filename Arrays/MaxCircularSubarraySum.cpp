#include<iostream>
#include<vector>

using namespace std;
int kadane(int arr[] , int n)
{
   int res = arr[0];
   int maxsumindex = arr[0];

   for(int i = 1; i < n; i++)
      {
         maxsumindex = max(maxsumindex + arr[i] , arr[i]);
         res = max(res , maxsumindex);
      }
   return res;
}

int circularSubarraySum(int arr[] , int n)
{
   int max_kadane = kadane(arr, n);
   int max_wrap = 0;

   for(int i = 0; i < n ; i++)
      {
         max_wrap += arr[i];
         arr[i] = -arr[i];
      }
   max_wrap += kadane(arr , n);
   return (max_wrap > max_kadane)? max_wrap : max_kadane;
}

int main()
{
   int arr[] = {10 ,-3 ,-4 ,7, 6, 5 ,-4 ,-1};
   cout<<circularSubarraySum(arr, sizeof(arr)/sizeof(arr[0]));
}
