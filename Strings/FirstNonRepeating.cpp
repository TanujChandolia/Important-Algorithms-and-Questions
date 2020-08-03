#include<iostream>
#include<cstring>
#include<utility>
#include<climits>
using namespace std;
char leftnonrepeat(string str)
{
   pair<int,int> freq[256];

   for(int i = 0; i < str.size(); i++)
   {
      (freq[str[i]].first)++;
      freq[str[i]].second = i;
   }
   int res = INT_MAX;
   for(int i = 0; i < 256; i++)
   {
      if(freq[i].first == 1)
         res = min(res , freq[i].second);
   }
   return str[res];
}
int main()
{
   string str = "hello";
   cout<<leftnonrepeat(str);
}
