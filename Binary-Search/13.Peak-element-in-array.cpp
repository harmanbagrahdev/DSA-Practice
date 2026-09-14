// Given an array of length N, peak element is defined as the element greater than both of its neighbors.
// Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i].
// Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

#include <bits/stdc++.h>
using namespace std;

// T = O(n)
// S = O(1)
int peakElement(vector<int>& nums) {
  int n = nums.size();

  if(nums[0] > nums[1]) return 0;
  else if(nums[n-1] > nums[n-2]) return n-1;

  for(int i = 1; i < n-1; i++) {
    if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
  }

  return -1;
}

// T = O(log(n))
// S = O(1)
int peakElementOptimal(vector<int>& nums) {
  int n = nums.size();
  int low = 0, high = n - 1;

  if(n == 1) return 0;

  while(low < high) {
    int mid = (low + high) / 2;

    if(nums[mid] > nums[mid+1]) high = mid;
    else low = mid+1;
  }

  return low;
}

int main() {
  vector<int> nums = {1,2,3,4,5,6,7,8,5,1};

  // cout << peakElement(nums) << endl;

  cout << peakElementOptimal(nums) << endl;
}