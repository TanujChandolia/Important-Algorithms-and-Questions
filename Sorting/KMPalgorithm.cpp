#include<iostream>
#include<cstring>

using namespace std;

void computeLPS(int lps[] , string pat){
   int len = 0;
   lps[0] = 0;
   int i = 1;
   while(i < pat.length()){
      if(pat[len] == pat[i]){
         lps[i] = ++len;
         i++;
      }
      else{
         if(len == 0){
            lps[i] = 0;
            i++;
         }
         else
            len = lps[len - 1];
      }
   }
}
void KMP(string txt , string pat){
   int lps[pat.length()];
   computeLPS(lps , pat);
   int i = 0 , j = 0;
   bool flag = false;
   while(i < txt.length()){
      if(txt[i] == pat[j]){
         i++;j++;
      }
      if(j == pat.length()){
         cout<<"Pattern found at index "<<i - j<<endl;
         flag = true;
         j = lps[j - 1];
      }

      else if(i < txt.length() && txt[i] != pat[j]){
         if(j == 0)
            i++;
         else
            j = lps[j - 1];
      }
   }

   if(flag == false)
      cout<<"Pattern not found";
}
int main(){
   string txt = "geeksforgeeks";
   string pat = "ee";

   KMP(txt , pat);
}
