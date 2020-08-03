#include<bits/stdc++.h>
using namespace std;

string findPermutation(string s, int n){
   string ans = "";
   int k = 0, sum = 0;
   int len = s.length();

   vector<int> fact(20,0);
   fact[0] = 1;
   fact[1] = 1;
   for(int i = 2; i < 20; i++){
      fact[i] = i*fact[i-1];
   }

   vector<int> freq(26,0);
   for(int i = 0; i < len; i++){
      freq[s[i]-'a']++;
   }

   while(sum != n){
      sum = 0;
      for(int i = 0; i < 26; i++){
         if(freq[i] == 0) continue;

         freq[i]--;
         int xsum = fact[len-1-k];
         for(int j = 0; j < 26; j++){
            xsum /= fact[freq[j]];
         }
         sum += xsum;

         if(sum >= n){
            ans += (i + 'a');
            k++;
            n -= (sum - xsum);
            break;
         }

         else if(sum < n)
            freq[i]++;
      }
   }

   for(int i = 25; i >= 0 && k < len; i--){
      if(freq[i]){
         ans += (i+'a');
         k++;
         freq[i]--;
         i++;
      }
   }

   return ans;
}
int main(){
   string s;
   cin >> s;

   int n; cin >> n;
   cout<<findPermutation(s,n);
}
