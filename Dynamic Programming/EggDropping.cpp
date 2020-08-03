#include<bits/stdc++.h>
using namespace std;
int egg(int n, int k){
   int dp[n+1][k+1];
   int res;

   for(int i = 0; i <= n; i++){
      dp[i][0] = 0;
      dp[i][1] = 1;
   }
   for(int j = 0; j <= k; j++){
      dp[0][j] = 0;
      dp[1][j] = j;
   }
   for(int i = 2; i <= n; i++){
      for(int j = 2; j <= k; j++){
         dp[i][j] = INT_MAX;
         for(int x = 1; x <= j; x++){
            res = 1 + max(dp[i-1][x-1] , dp[i][j-x]);
            dp[i][j] = min(dp[i][j], res);
         }
      }
   }


   for(int i = 0; i <= n; i++){
      for(int j = 0; j <= k; j++)
         cout<<dp[i][j]<<" ";
      cout<<"\n";
   }

   return dp[n][k];
}

int main(){
   int n,k;
   cin >> n >> k;
   cout<<egg(n,k);
}
