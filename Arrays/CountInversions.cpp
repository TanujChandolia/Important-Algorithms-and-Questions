#include<iostream>
#include<map>
using namespace std;
int merge(int arr[] , int l , int m , int r)
{
   for(int i = l; i <= r; i++)
      cout<<arr[i]<<" ";
   cout<<endl;
   int n1 = m - l + 1;
   int n2 = r - m;
   int L[n1], R[n2];
   for(int i = 0; i < n1; i++)
      L[i] = arr[l + i];
   for(int i = 0; i < n2; i++)
      R[i] = arr[m + 1 + i];

   int i = 0 , j = 0, k = l ,res = 0;
   while(i < n1 && j < n2)
   {
      if(L[i] <= R[j])
         {
            arr[k] = L[i];
            i++;
         }
      else
         {
            arr[k] = R[j];
            j++;
            res = res + (n1 - i);
         }
      k++;
   }
   while(i < n1)
      {
         arr[k] = L[i]; i++; k++;
      }
   while(j < n2)
      {
         arr[k] = R[j]; j++; k++;
      }
   return res;

}
int mergesort(int arr[] , int l , int r )
{
   int res = 0;
   if(r > l)
   {
      int m = (l+r)/2;
      res += mergesort(arr , l , m);
      res += mergesort(arr , m+1 , r);
      res += merge(arr, l , m , r);
   }
   return res;
}
int main()
{
   int arr[] = {4,3,2,1};
   cout<<mergesort(arr, 0 , 3);
}
