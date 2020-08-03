#include<bits/stdc++.h>
using namespace std;
void previousSmaller(int arr[] , int n){
   stack<int> st;
   int S[n];
   S[0] = -1;
   st.push(0);
   for(int i = 1; i < n; i++){
      while(!st.empty() && arr[i] <= arr[st.top()])
         st.pop();
      S[i] = (st.empty())? -1: st.top();
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
   previousSmaller(arr,n);
}
