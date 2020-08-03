#include <bits/stdc++.h>
using namespace std;
int m = 1e9 + 7;
int power(int n , int p){
   long long res = 1;
   n %= m;
   while(p > 0){
      if(p % 2 == 1){
         res*= n;
         res %= m;
      }
      n *= n; n %= m;
      p /= 2;
   }
   return res;
}

int main() {
   int n; cin >> n;
   int pow; cin >> pow;
   cout<<power(n,pow);
}
