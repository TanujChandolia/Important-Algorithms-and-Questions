#include<iostream>
#include<unordered_map>

using namespace std;
void LongestSubarray(int arr[] , int n , int sum)
{
   unordered_map<int,int> mp;
   int prefix = 0;
   int res = 0;
   for(int i = 0; i< n; i++)
   {
      prefix += arr[i];
      if(prefix == sum)
         res = i+1;
      if(mp.find(prefix) == mp.end())
         mp[prefix] = i;
      if(mp.find(prefix - sum) != mp.end())
         res = max(res , i - mp[prefix - sum]);
   }

   cout<<res;
}
int main()
{
   int arr[] = {5,4,7,2,8,3,9};
   int n = sizeof(arr)/sizeof(arr[0]);
   int sum = 18;

   LongestSubarray(arr , n, sum);
}
