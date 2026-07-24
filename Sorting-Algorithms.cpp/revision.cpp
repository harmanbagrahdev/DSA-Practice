#include <bits/stdc++.h>
using namespace std;

int partitionArr(vector<int>& arr, int low, int high) {
  int pivot = arr[low];
  int i = low, j = high;

  while(i < j) {
    
    while(arr[i] <= pivot && i <= high - 1) i++; // high - 1 just because i++ could exceed array boundry same for low + 1

    while(arr[j] > pivot && j >= low + 1) j--;
    
    if(i < j) swap(arr[i], arr[j]);
  }
  
  swap(arr[low], arr[j]); // swapping pivot with last element in subarray

  return j; // return pivotIndex
}

void quickSort(vector<int>& arr, int low, int high) {
  if(low < high) {
    int pivotIndex = partitionArr(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  }
}

int main() {
  vector<int> arr = {55,45,35,75,25,5};

  quickSort(arr, 0, arr.size()-1);
  for(auto i : arr) {
    cout << i << " ";
  } cout << endl;
}