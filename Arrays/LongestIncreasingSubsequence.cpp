#include<bits/stdc++.h>
using namespace std;
int lis(int arr[] , int n){
   int len = 1;
   vector<int> tail;
   tail.push_back(arr[0]);

   for(int i = 1; i < n; i++){
      if(arr[i] > tail[len-1]){
         tail.push_back(arr[i]);
         len++;
      }
      else{
         int idx = lower_bound(tail.begin() , tail.begin() + (len-1), arr[i]) - tail.begin();
         tail[idx] = arr[i];
      }
   }
   return len;
}
int main(){
   int n; cin >> n;
   int arr[n];
   for(int i = 0; i < n; i++)
      cin >> arr[i];
   cout<<lis(arr , n);
}
