// Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T = O(n)
// S = O(1)
bool searchEl(vector<int>& nums, int k) {
  for(int i = 0; i < nums.size(); i++) {
    if(k == nums[i]) return true;
  }
  return false;
}

// Brute force
// T = O(log(n))
// S = O(1)
bool searchElOptimal(vector<int>& nums, int k) {
  int n = nums.size();
  int low = 0, high = n-1;
  
  while(low <= high) {
    int mid = (low + high) / 2;

    if(k == nums[mid]) return 1;

    // when low and mid match
    if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
      low++;
      high--;
    }

    else if(nums[low] <= nums[mid]) {
      if(nums[low] <= k && k < nums[mid]) high = mid-1;
      else low = mid+1;
    }

    else if(nums[high] >= nums[mid]) {
      if(nums[mid] < k && k <= nums[high]) low = mid+1;
      else high = mid-1;
    }
  }

  return 0;
}

int main() {
  vector<int> nums = {1,0,1,1,1};
  int k = 0;

  cout << searchEl(nums, k) << endl;
}