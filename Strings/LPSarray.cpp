#include<iostream>
#include<cstring>

using namespace std;

void constructLps(string s){

   int lps[s.length()];
   int len = 0;
   lps[0] = 0;
   int i = 1;

   while(i < s.length()){
      if(s[i] == s[len]){
         lps[i] = ++len;
         i++;
      }
      else{
         if(len == 0){
            lps[i] = 0; i++;
         }
         else
            len = lps[len - 1];
      }
   }
   for(int i = 0; i < s.length(); i++)
      cout<<lps[i]<<" ";
}
int main(){
   string str;
   cin >> str;
   constructLps(str);
}
