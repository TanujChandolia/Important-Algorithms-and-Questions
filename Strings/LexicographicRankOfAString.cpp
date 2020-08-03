#include<iostream>
#include<string>

using namespace std;
int factorial(int n)
{
   return (n==0||n==1)?1:n*factorial(n-1);
}
int main()
{
   string s = "string";
   int freq[256] = {0};
   for(int i = 0; i < s.length(); i++)
      freq[s[i]]++;

   int n = s.length();
   int mul = factorial(n);
   for(int i = 1; i < 256;i++)
      freq[i] += freq[i-1];
   int res = 1;

   for(int i = 0; i < n; i++)
   {
      mul = mul/(n-i);
      res += mul*(freq[s[i]] - 1);
      for(int j = s[i]; j < 256; j++)
            freq[j]--;
   }
   cout<<res;
   return 0;
}
