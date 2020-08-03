#include<bits/stdc++.h>
using namespace std;
void rollingHash(string s){
   long long d = 26;
   long long mod = 1e9+7;
   int low = 1;
   long long h = 1, t = 0;
   while(low <= s.length()-2){
      vector<long long> hash;
      h = 1;
      t = 0;
      for(int i = 1; i < low; i++)
         h = (h*d)%mod;
      for(int i = 0; i < low; i++){
         t = (t*d + s[i]) % mod;
      }
      hash.push_back(t);
      for(int i = 1; i <= s.length()-low; i++){
         t = (d*(t - s[i-1]*h) + s[i-1+low])%mod;
         if(t < 0)
            t += mod;
         hash.push_back(t);
      }

      for(int x:hash)
         cout<<x<<" ";
      cout<<"\n";
      low++;
   }
}
int main(){
   string s;
   cin >> s;
   rollingHash(s);
}
