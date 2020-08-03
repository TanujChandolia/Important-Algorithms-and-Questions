#include<bits/stdc++.h>
using namespace std;

int LargestRectangle(int arr[] , int n){
   stack<int> st;
   int maxArea = 0;
   int top;
   int area_with_top;

   int i = 0;
   while(i < n){
      if(st.empty() || arr[st.top()] <= arr[i])
         st.push(i++);
      else{
         top = st.top();
         st.pop();
         area_with_top = arr[top] * ( st.empty()? i : i - st.top() - 1 );
         maxArea = max(maxArea , area_with_top);
      }
   }

   while(!st.empty()){
      top = st.top();
      st.pop();
      area_with_top = arr[top] * ( st.empty()? i : i - st.top() - 1 );
      maxArea = max(maxArea , area_with_top);
   }
   return maxArea;
}
int main(){
   int n; cin >> n;
   int arr[n];
   for(int i = 0; i<n; i++)
      cin >> arr[i];
   cout<<LargestRectangle(arr , n);
}
