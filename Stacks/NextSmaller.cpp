#include<bits/stdc++.h>
using namespace std;

void nextSmaller(int arr[] , int n){
   int S[n];
   S[n-1] = n;
   stack<int> st;
   st.push(n-1);

   for(int i = n-2; i >= 0; i--){
      while(!st.empty() && arr[st.top()] >= arr[i])
         st.pop();
      S[i] = (st.empty())? n: st.top();
      st.push(i);
   }

   for(int i = 0; i < n; i++)
      cout<<S[i]<<" ";
}
int main(){
   int n;
   cin >> n;
   int arr[n];
   for(int i = 0; i < n; i++)
      cin >> arr[i];
   nextSmaller(arr,n);
}
