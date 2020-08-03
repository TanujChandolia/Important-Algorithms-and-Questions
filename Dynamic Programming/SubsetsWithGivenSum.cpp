#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int> arr = {1,5,11,5};
   int sum = 11 ;
   vector<int> dp(sum+1,0);
   dp[0] = 1;
   for (int n : arr){
      for (int i = sum; i >= n; i--){
          dp[i] += dp[i - n];
      }
      for(int x:dp)
        cout<<x<<" ";
      cout<<"\n";
   }
}
