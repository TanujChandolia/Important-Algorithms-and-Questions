#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> arr,int k){
   int n = arr.size();
   if(k > n/2){
      int ans;
      for(int i = 1; i < n; i++){
         ans += max(arr[i]-arr[i-1],0);
      }
      return ans;
   }

   vector<vector<int>> dp(k+1,vector<int> (n+1,0));
   for(int i = 1; i <= k; i++){
      int prev_diff = INT_MIN;
      for(int j = 1; j < n; j++){
         prev_diff = max(prev_diff, dp[i-1][j-1] - arr[j-1]);
         dp[i][j] = max(dp[i][j-1], arr[j]+prev_diff);
      }
   }

   return dp[k][n-1];
}
int main(){
   int n; cin >> n;
   vector<int> arr(n);

   for(int i = 0; i < n; i++)
      cin >> arr[i];
   int k; cin >> k;
   cout<<maxProfit(arr,k);
}
