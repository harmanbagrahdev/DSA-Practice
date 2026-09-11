// Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n)
// S = O(1)
int searchEl(vector<int>& nums, int& x) {
  int n = nums.size();

  for(int i = 0; i < n; i++) {
    if(nums[i] == x) return i;
  }
  return -1;
}

// Optimal solution
// T = O(log(n))
// S = O(1)
int searchElOptimal(vector<int>& nums, int& x) {
  int n = nums.size();
  int low = 0, high = n-1;

  while(low <= high) {
    int mid = (low + high) / 2;

    if(nums[mid] == x) return mid;
    
    // check if left part is sorted
    else if(nums[low] <= nums[mid]) {

      if(nums[low] <= x && x < nums[mid]) {
        high = mid-1;
      }
      else low = mid+1;
    }

    // check if right part is sorted
    else if(nums[high] >= nums[mid]) {

      if(nums[high] >= x && x > nums[mid]) {
        low = mid+1;
      }
      else high = mid-1;
    }
  }

  return -1;
}

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int x = 0;

  // cout << searchEl(nums, x) << endl;

  cout << searchElOptimal(nums, x) << endl;
}