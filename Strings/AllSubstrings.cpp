#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> v;
void substrings(string a , string curr = "" , int index = 0)
{
   if(index == a.length())
      {
         v.push_back(curr);
         return;
      }
   substrings(a , curr , index + 1);
   substrings(a , curr + a[index] , index + 1);
}

int main()
{
   string a = "ABC";
   substrings(a);
   sort(v.begin() , v.end());
   for(auto x:v)
      cout<<x<<" ";
}
