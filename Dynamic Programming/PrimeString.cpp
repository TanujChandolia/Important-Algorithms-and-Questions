#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
const int maxn = 1000001;
vector<bool> prime(maxn , true);

void sieve(){
   prime[0] = prime[1] = false;
   for(int i = 2; i*i <= maxn; i++){
      if(prime[i] == true){
         for(int j = i*i; j <= maxn; j += i)
            prime[j] = false;
      }
   }
}

int countPrimeString(string s){
   int n = s.length();
   int dp[n+1] = {0};
   dp[0] = 1;
   for(int i = 1; i <= n; i++){

      if(s[i-1] != '0' && prime[stoi(s.substr(i-1,1))])
         dp[i] = dp[i-1];
      for(int j = 2; j <= 6; j++){        //j = 6 because we have to calculate primes between 2 and 10^6;
         if(i - j >= 0){
            if(s[i - j] != '0' && prime[stoi(s.substr(i-j,j))])
               dp[i] = (dp[i] + dp[i-j]) %mod;
         }
      }
   }
   return dp[n];
}


int main(){
   sieve();
   string s;
   cin >> s;
   cout<< countPrimeString(s);
}
