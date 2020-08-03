#include<bits/stdc++.h>
using namespace std;
int ncr(int n, int r){
   if(r > n)
      return -1;
   if(r > n-r)
      r = n-r;
   int dp[r+1] = {0};
   dp[0] = 1;
   for(int i = 1; i <=n ;i++){
      for(int j = min(i,r); j > 0; j--)
         dp[j] += dp[j-1];
   }
   return dp[r];
}
int main(){
   int n,r;
   cin >> n >> r;
   cout<<ncr(n,r)<<endl; 
}
