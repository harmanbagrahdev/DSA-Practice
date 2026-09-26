// A peak element is an element that is strictly greater than its neighbors.
// Given a 0-indexed integer array nums, find a peak element, and return its index.
// If the array contains multiple peaks, return the index to any of the peaks.
// You may assume that an element is always considered to be strictly greater than a neighbor that is outside the array boundary (nums[-1] = nums[n] = -INF).

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n)
// S = O(1)
int peakElement(vector<int>& nums) {
  int n = nums.size();
  
  if(n == 1) return 0;
  else if(n >= 2 && nums[0] > nums[1]) return 0;
  else if(nums[n-1] > nums[n-2]) return n-1;

  for(int i = 1; i < n-1; i++) {
    if(nums[i] > nums[i+1] && nums[i] > nums[i-1]) return i;
  }
  return -1;
}

// Optimal
// T = O(log(n))
// S = O(1)
int peakElementOptimal(vector<int>& nums) {
  int low = 0, high = nums.size() - 1;

  while(low < high) {
    int mid = (low + high) / 2;

    if(nums[mid] > nums[mid+1]) high = mid;
    else low = mid+1;
  }

  return low;
}

int main() {
  vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

  // cout << peakElement(nums) << endl;

  cout << peakElementOptimal(nums) << endl;
}