#include<iostream>
#include<vector>
#include<cstring>

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

int main()
{
   int arr[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
   cout<<kadane(arr , sizeof(arr)/sizeof(arr[0]));
}
