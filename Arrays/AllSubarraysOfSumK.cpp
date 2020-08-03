#include<iostream>
#include<unordered_map>
using namespace std;
void allsubarrays(int arr[] , int n , int sum)
{
   int prefix = 0;
   unordered_map<int, int> m;
   int res = 0;
   for(int i = 0; i < n; i++)
   {
      prefix += arr[i];
      if(prefix == sum)
         res++;
      if(m.find(prefix - sum) != m.end())
         res += m[prefix -sum];
      m[prefix]++;
   }

   cout<<res;
}
int main()
{
      int arr[] = {1,9,2,6,8,4,3};
      int n = sizeof(arr)/sizeof(arr[0]);
      int sum = 8;

      allsubarrays(arr , n, sum);
}
