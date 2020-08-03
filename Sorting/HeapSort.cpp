#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>& arr,int n ,int i){
   int largest = i;
   int l = 2*i + 1;
   int r = 2*i + 2;
   if(l < n && arr[l] > arr[largest])
      largest = l;
   if(r < n && arr[r] > arr[largest])
      largest = r;
   if(largest != i){
      swap(arr[largest],arr[i]);
      heapify(arr,n,largest);
   }
}
void buildheap(vector<int>& arr){
   int n = arr.size();
   for(int i = (n-1)/2; i>=0; i--)
      heapify(arr,n,i);
}
void heapsort(vector<int>& arr){
   int n = arr.size();
   buildheap(arr);
   for(int i = n-1; i >= 0; i--){
      swap(arr[0],arr[i]);
      heapify(arr,i,0);
   }
}
int main(){
   int n;  cin >> n;
   vector<int> arr(n);

   for(int i = 0; i < n; i++)
      cin >> arr[i];
   heapsort(arr);
   for(int i:arr)
      cout<<i<<" ";
}
