#include<iostream>

using namespace std;

int main()
{
   int arr[] = {1,3,3};
   int n = sizeof(arr)/sizeof(arr[0]);

   for(int i = 0; i < n; i++)
   {
      if( (abs(arr[i]) - 1) < n && arr[abs(arr[i])-1] > 0)
         arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
   }

   for(int i = 0; i < n; i++)
      if(arr[i] > 0)
         cout<<i+1;
}
