#include <bits/stdc++.h>
using namespace std;

// merge sort

void merge(vector<int>& arr, int low, int mid, int high) {
  vector<int> temp;
  int left = low, right = mid + 1;
  while(left <= mid && right <= high) {
    if(arr[left] <= arr[right]) {
      temp.push_back(arr[low++]);
    }
    else{
      temp.push_back(arr[right++]);
    }
  }

  while(left <= mid) {
    temp.push_back(arr[left++]);
  }

  while(right <= high) {
    temp.push_back(arr[right++]);
  }

  for(int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

void mergeSort(vector<int>& arr, int low, int high) {
  if(low >= mid) retrun;

  int mid = (low + high)/2;

  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);

  merge(arr, low, mid, high);
}

int main() {
  vector<int> arr = {1,2,3,4,5,4,1,2,15,54,8};
  
  mergeSort(arr, 0, size(arr));
}