#include<iostream>
#include<cstring>
#define d 256
using namespace std;
bool RabinKarp(string txt , string pat, int n , int m, int q){
   int h = 1;
   int p = 0, t = 0;

   for(int i = 1; i < m; i++){
      h = (h * d) % q;
      //cout<<"h: "<<h<<"\n";
   }
   for(int i = 0; i < m; i++){
      p = (p*d + pat[i]) % q;
      t = (t*d + txt[i]) % q;
   }

   for(int i = 0; i <= n-m; i++){
      if(p == t){
         int j;
         for(j = 0; j < m; j++)
            if(txt[i+j] != pat[j])
               break;
         if(j == m)
            return true;
      }

      if(i < n-m){
         t = (d*(t - txt[i]*h) + txt[i+m])% q;
         if(t < 0)
            t += q;
      }
   }
   return false;
}

int main(){
   string txt = "geeksforgeeks";
   string pat = "ksf";

   if(RabinKarp(txt , pat , txt.length() , pat.length() , 1000000007) == 1)
         cout<<"Yes";
   else
         cout<<"No";
}
