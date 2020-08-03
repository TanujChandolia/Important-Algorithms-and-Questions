#include<bits/stdc++.h>
using namespace std;
bool subsetsum(int arr[], int n, int val){
   int sum = 0;
   for(int i = 0; i < n; i++)
      sum += arr[i];
   bool dp[n+1][sum+1];
   for(int i = 0; i <= n; i++)
      dp[i][0] = true;
   for(int i = 1; i <= sum; i++)
      dp[0][i] = false;

   for(int i = 1; i <= n;i++){
      for(int j = 1; j <= sum; j++){
         if(j < arr[i-1])
            dp[i][j] = dp[i-1][j];
         else
            dp[i][j] = dp[i-1][j]||dp[i-1][j - arr[i-1]];
      }
   }
   return dp[n][val];
}
int main(){
   int n; cin >> n;
   int arr[n];
   for(int i = 0; i < n; i++)
      cin >> arr[i];
   int sum;
   cin >> sum;
   cout<<subsetsum(arr,n,sum)<<endl;
}
