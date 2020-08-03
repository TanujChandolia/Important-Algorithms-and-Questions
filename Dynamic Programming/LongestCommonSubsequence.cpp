#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int n, int m){
   int dp[n+1][m+1];
   for(int i = 0; i <= n; i++)
      dp[i][0] = 0;
   for(int j = 0; j <= m; j++)
      dp[0][j] = 0;

   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
         if(s1[i-1] == s2[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
         else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
   }


   for(int i = 0; i <= n; i++){
      for(int j = 0; j <= m; j++)
         cout<<dp[i][j]<<" ";
      cout<<"\n";
   }
   string ans = "";
   int i = n, j = m;
   while(i > 0 && j > 0){
      if(s1[i-1] == s2[j-1]){
         ans += s1[i-1];
         i--; j--;
      }
      else{
         if(dp[i-1][j] >= dp[i][j-1])
            i--;
         else
            j--;
      }
   }
   reverse(ans.begin(), ans.end());
   cout<<ans<<endl;

   return dp[n][m];
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   string s1;
   string s2;
   cin >> s1 >> s2;
   cout<<lcs(s1,s2,s1.size(),s2.size());
}
