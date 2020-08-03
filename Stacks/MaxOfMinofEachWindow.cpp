#include<bits/stdc++.h>
using namespace std;

void MaxOfMin(int arr[] , int n){
   stack<int> st;
   int NSE[n];
   int PSE[n];

   PSE[0] = -1;
   st.push(0);
   for(int i = 1; i < n; i++){
      while(!st.empty() && arr[i] <= arr[st.top()])
         st.pop();
      PSE[i] = (st.empty())? -1: st.top();
      st.push(i);
   }

   while(!st.empty())
      st.pop();

   NSE[n-1] = n;
   st.push(n-1);
   for(int i = n-2; i >= 0; i--){
      while(!st.empty() && arr[st.top()] >= arr[i])
         st.pop();
      NSE[i] = (st.empty())? n: st.top();
      st.push(i);
   }

   int ans[n+1] = {0};
   for(int i = 0; i < n ; ++i){
      int len = NSE[i] - PSE[i] - 1;
      ans[len] = max(ans[len] , arr[i]);
   }

   for(int i = n-1; i>= 1; --i)
      ans[i] = max(ans[i] , ans[i+1]);

   for(int i = 1; i <= n; i++)
      cout<<ans[i]<<" ";
}
int main(){
   int n; cin >> n;
   int arr[n];
   for(int i = 0 ; i < n; i++)
      cin >> arr[i];
   MaxOfMin(arr , n);
}
