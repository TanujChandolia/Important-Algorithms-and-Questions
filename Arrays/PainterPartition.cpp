#include<iostream>
using namespace std;
int getMax(int arr[] , int n){
   int maxele = -1;
   for(int i = 0; i < n; i++)
      maxele = max(maxele , arr[i]);
   return maxele;
}
int getSum(int arr[] , int n){
   int total = 0;
   for(int i = 0; i < n; i++)
      total += arr[i];
   return total;
}
int getPainters(int arr[] , int n , int mid){
   int total = 0, painters = 1;
   for(int i = 0 ; i < n; i++){
      total += arr[i];
      if(total > mid){
         cout<<"total = "<<total<<" at i = "<<i+1<<endl;
         total = arr[i];
         painters ++;
         cout<<"painters = "<<painters<<endl;
      }
   }
   return painters;
}
int partition(int arr[] , int n , int k){
   int low = getMax(arr , n);
   int high = getSum(arr,  n);
   while(low < high){
      int mid = (low+high)/2;
      cout<<"low: "<<low<<"\nhigh: "<<high<<"\nmid: "<<mid<<endl;
      int reqpainters = getPainters(arr , n , mid);
      if(reqpainters <= k)
         high = mid;
      else
         low = mid + 1;
   }
   return low;
}
int main(){
   int arr[] = {10,10,10,10};
   int n = sizeof(arr)/sizeof(arr[0]);
   int k = 2;
   cout<<partition(arr,n,k);
}
