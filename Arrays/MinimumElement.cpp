#include<bits/stdc++.h>
using namespace std;

int minEle(vector<int> arr){
   int n = arr.size();
   if(n == 1)
      return arr[0];
   int low  = 0, high = n-1;
   if(arr[low] < arr[high])
      return arr[low];

   while(low <= high){
      int mid = (low + high)/2;
      if(low < mid && arr[mid-1] > arr[mid])
         return arr[mid];
      else if(high > mid && arr[mid+1] < arr[mid])
         return arr[mid+1];
      else if(arr[high] > arr[mid])
         high = mid-1;
      else
         low = mid + 1;
   }
   return arr[low];
}
int main(){
   int n; cin >> n;
   vector<int> arr(n);
   for(int i = 0; i < n; i++)
      cin >>  arr[i];

   cout<<minEle(arr);
}
