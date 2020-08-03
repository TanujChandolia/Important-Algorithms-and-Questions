#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;
//max Substring with Distinct characters
int maxSubstring(string s){
   unordered_map<char , int> mp;
   int res = 0;

   int i = 0 , j = 0;
   while(j < s.length()){
      mp[s[j]]++;

      while(mp[s[j]] > 1){
         mp[s[i]]--;
         i++;
      }

      res = max(res , j - i + 1);
      j++;
   }
   return res;
}

int main(){
   string s = "abaacdbab";
   cout<<maxSubstring(s);
}
