#include<bits/stdc++.h>
using namespace std;

int LargestRectangle(int arr[] , int n){
   int LGE[n], RGE[n];
   stack<int> st;

   LGE[0] = 0;
   st.push(0);
   for(int i = 1; i < n; i++){
      while(!st.empty() && arr[st.top()] >= arr[i])
         st.pop();
      LGE[i] = (st.empty())?i: i - st.top() - 1;
      st.push(i);
   }

   while(!st.empty())
      st.pop();

   RGE[n-1] = 0;
   st.push(n-1);
   for(int i = n-2; i>=0; i--){
      while(!st.empty() && arr[st.top()] >= arr[i])
         st.pop();
      RGE[i] = (st.empty())? (n-i-1): (st.top() - i - 1);
      st.push(i);
   }

   int res = 0;
   for(int i = 0; i < n; i++){
      int curr = arr[i]*(1 + LGE[i] + RGE[i]);
      res = max(res , curr);
   }
   return res;
}
int main(){
   int n; cin >> n;
   int arr[n];
   for(int i = 0; i<n; i++)
      cin >> arr[i];
   cout<<LargestRectangle(arr , n);
}
