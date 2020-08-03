#include<iostream>
using namespace std;
void BinarySearch(int arr[], int val, int n)
{
   int l = 0 , r= n-1;
   while( l <= r)
      {
         int mid = (l + r)/2;
         if(arr[mid] == val)
            {
               cout<<mid<<endl;
               return;
            }
         else if(val < arr[mid])
            {
               r = mid - 1;
            }
         else
            {
               l = mid + 1;
            }
      }
   cout<<"-1";
}

int main()
{
   int arr[] = {1,2,3,4};
   cout<<"Enter the value to be searched: ";int val; cin >>val;
   BinarySearch(arr,val,sizeof(arr)/sizeof(arr[0]));
   return 0;
}
