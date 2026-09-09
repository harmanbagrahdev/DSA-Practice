#include <bits/stdc++.h>
using namespace std;

// Iterative version
// T = O(log(n))
// S = O(1)
int binarySearch(vector<int>& arr, int &target) {
  int n = arr.size();
  int low = 0;
  int high = n-1;
  
  while(low <= high) {
    int mid = (low + high) / 2;
    if(arr[mid] == target) return mid;
    else if(target < arr[mid]) high = mid-1;
    else low = mid + 1;
  }
  return -1;
}

// Recursive version
// T = O(log(n))
// S = O(1)
int binarySearchRecursion(vector<int>& arr, int& target, int low, int high) {
  int n = arr.size();
  if(low > high) return -1;

  // In case the search space is from 0 to INT16_MAX then mid can overflow so we can use long long or just apply a mathematical tweaking!
  // int mid = (low + high) / 2;
  int mid = low + (high - low) / 2;
  if(arr[mid] == target) return mid;
  else if(target > arr[mid]) return binarySearchRecursion(arr, target, mid+1, high);
  return binarySearchRecursion(arr, target, low, mid-1);
}

int main() {
  vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
  int target = 6;

  // cout << binarySearch(arr, target) << endl;

  cout << binarySearchRecursion(arr, target, 0, arr.size() - 1) << endl;
}