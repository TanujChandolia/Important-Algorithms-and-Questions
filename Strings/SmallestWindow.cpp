#include<iostream>
#include<cstring>

using namespace std;
string smallestWindow(string s , string pat){
   if(pat.length() > s.length())
      return "-1";

   int hash_pat[256] = {0};
   int hash_str[256] = {0};

   for(int i = 0 ; i < pat.length(); i++)
      hash_pat[pat[i]]++;

   int count = 0;
   int start = 0;
   int startindex = -1;
   int minwindow = s.length();

   for(int i = 0; i < s.length(); i++){
      hash_str[s[i]]++;

      if(hash_pat[s[i]] != 0 && hash_str[s[i]] <= hash_pat[s[i]] )
         count++;

      if(count == pat.length()){
         while(hash_str[s[start]] > hash_pat[s[start]] || hash_pat[s[start]] == 0){

            if(hash_str[s[start]] > hash_pat[s[start]])
               hash_str[s[start]]--;
            start++;
         }
         int len_window = i - start + 1;
         if(minwindow >= len_window){
            minwindow = len_window;
            startindex = start;
         }
      }
   }

   if(startindex == -1)
      return "-1";

   else
      return(s.substr(startindex , minwindow));
}
int main(){
   string s = "timetopractice";
   string pat = "toc";

   cout<<smallestWindow(s , pat);
}
