#include<bits/stdc++.h>
using namespace std;
int maxval(int arr[] ,int n){
   int dp[n][n];
   for(int i = 0; i < n-1; i++)
      dp[i][i+1] = max(arr[i], arr[i+1]);

   for(int gap = 3; gap < n; gap += 2){
      for(int i = 0; i+gap < n; i++){
         int j = i + gap;
         dp[i][j] = max(arr[i] + min(dp[i+2][j],dp[i+1][j-1]) , arr[j] + min(dp[i][j-2], dp[i+1][j-1]));
      }
   }

   return dp[0][n-1];
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n; cin >> n;
   int arr[n];
   for(int i = 0; i < n; i++)
      cin >> arr[i];
   cout<<maxval(arr,n);
}
