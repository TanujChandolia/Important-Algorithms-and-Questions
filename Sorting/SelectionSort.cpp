#include <iostream>
using namespace std;

int min(int arr[], int i , int size){

  int min = arr[i];
  int loc = i;
  for(int j = i + 1; j < size; j++){
    if(arr[j] < min){
      min = arr[j];
      loc = j;
    }
  }

  return loc;
}

void SelectionSort(int arr[],int size){
  int minloc;
  for(int i =0 ; i < size; i ++ ){
    minloc = min(arr , i , size);
    int temp = arr[i];
    arr[i] = arr[minloc];
    arr[minloc] = temp;
  }

  for(int i = 0 ; i < size; i ++ ){
    cout<<arr[i]<< " ";
  }
}

int main(){
  int arr[] = {77,33,44,11,88,22,66,55};
  SelectionSort(arr,8);
  return 0;
}
