#include <iostream>
using namespace std;

void MergeToSort(int a[] , int sizea , int b[] , int sizeb){
  int i = 0 ,j = 0 , k = 0;
  int c[sizea + sizeb];
  while(i < sizea && j < sizeb){

    if(a[i] < b[j]){
      c[k] = a[i];
      k++; i++;
    }
    else{
      c[k] = b[j];
      k ++ ; j ++;
    }
  }

  while(i < sizea){
    c[k] = a[i];
    k ++ ; i ++;
  }

  while(j < sizeb){
    c[k] = b[j];
    k ++ ; j ++;
  }

  for(int i = 0 ; i < sizea + sizeb; i++){
    cout<<c[i] <<" ";
  }
}

int main(){
  int a[5] = {22,44,55,77,88};
  int b[3] = {33,66,70};

  MergeToSort(a,5,b,3);

  return 0;
}
