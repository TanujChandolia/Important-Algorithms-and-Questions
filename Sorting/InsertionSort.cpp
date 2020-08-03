#include <iostream>
using namespace std;

void insertionSort(int arr[],int size){

  int temp,ptr;
  for(int i = 1; i < size; i ++){

    temp = arr[i];
    ptr = i - 1;
    while(temp < arr[ptr]){

        arr[ptr+1] = arr[ptr];
        ptr = ptr - 1;
        if(ptr == -1)
          break;
    }
    arr[ptr + 1] = temp;
  }

  for(int i = 0 ; i < size; i ++){
    cout<<arr[i]<<" ";
  }
}
int main(){

  int arr[] = {77 , 33, 44 , 11, 88, 22 ,66, 55};

  insertionSort(arr,8);
}
