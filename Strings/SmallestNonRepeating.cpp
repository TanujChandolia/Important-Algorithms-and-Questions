#include<iostream>
#include<cstring>

using namespace std;
char smallestnonrepeat(string str)
{
   int freq[256];
   for(int i =0; i < 256; i++)
      freq[i] = -1;
   for(int i = 0; i < str.size(); i++)
   {
      if(freq[str[i]] == -1)
         freq[str[i]] = i;
      else
         freq[str[i]] = -2;
   }

   for(int i = 0; i < 256; i++)
   {
      if(freq[i] != -1 && freq[i] != -2)
         return (char)i;
   }
   return '$';
}
int main()
{
   string str = "hello";
   cout<<smallestnonrepeat(str);
}
