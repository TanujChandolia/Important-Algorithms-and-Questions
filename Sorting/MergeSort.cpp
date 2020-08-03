#include<iostream>
using namespace std;

void Merge(int arr[] , int l , int mid , int r){
  int i, j ,k;
  int n1 =  mid - l + 1;
  int n2 = r - mid;

  int L[n1] , R[n2];

  for(i = 0; i < n1 ; i++)
      {
        L[i] = arr[i + l];
      }
  for(j = 0; j < n2; j++)
      {
        R[j] = arr[j + mid + 1];
      }

  i = 0; j = 0; k = l;

  while(i < n1 && j < n2){

    if(L[i] < R[j]){
        arr[k] = L[i];
        i++;
    }
    else{
        arr[k] = R[j];
        j ++;
    }
    k++;
  }

  while(i < n1){
    arr[k] = L[i];
    i++;k++;

  }
  while(j < n2){
    arr[k] = R[j];
    j ++ ; k++;
  }

}

void MergeSort(int arr[] , int l , int r){

  if(l < r){
    int mid = (l+r) / 2;
    MergeSort(arr,l,mid);
    MergeSort(arr,mid+1,r);

    Merge(arr , l , mid , r);
  }
}

int main(){
  int arr[] = {0,0,0,0,1,1,1,1,0,0};
  int n =sizeof(arr)/sizeof(arr[0]);
  MergeSort(arr,0,n - 1);

  for(int i = 0; i < n ; i ++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}
