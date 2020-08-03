#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[] , int val[] , int w, int n){
   int dp[n+1][w+1];
   for(int i = 0; i <= w; i++)
      dp[0][i] = 0;
   for(int i = 0; i<= n; i++)
      dp[i][0] = 0;

   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= w; j++){
         if(wt[i-1] > j)
            dp[i][j] = dp[i-1][j];
         else
            dp[i][j] = max(dp[i-1][j] , val[i-1] + dp[i-1][j - wt[i-1]]);
      }
   }

   return dp[n][w];
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int wt[] = {10,7,4,2};
   int val[] = {60,28,20,24};
   int w = 11;
   int n = 4;
   cout<<knapsack(wt,val,w,n);
}
