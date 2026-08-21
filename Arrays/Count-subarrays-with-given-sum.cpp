// Given an array of integers and an integer k, return the total number of subarrays whose sum equals k. A subarray is a contiguous non-empty sequence of elements within an array.

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T = O(n^3)
// S = O(1)
int totalSubarraysBrute(vector<int>& nums, int k) {
  int n = nums.size();
  int cnt = 0;

  for(int i = 0; i < n; i++) {
    int start = i;

    for(int j = i; j < n; j++) {
      int end = j;
      int sum = 0;

      for(int m = start; m <= end; m++) {
        sum += nums[m];
      }
      if(sum == k) cnt++;
    }
  }

  return cnt;
}

// Better solution
// T = O(n^2)
// S = O(1)
int totalSubarraysBetter(vector<int>& nums, int k) {
  int n = nums.size();
  int cnt = 0;

  for(int i = 0; i < n; i++) {
    int start = i;
    int sum = 0;

    for(int j = i; j < n; j++) {
      sum += nums[j];
      if(sum == k) cnt++;
    }
  }

  return cnt;
}

// Optimal solution
// T = O()
// S = O()
int totalSubarraysOptimal(vector<int>& nums, int k) {
  // the array contains negatives also so this will approach will fail! The optimal solution uses hash map and pre fix sum method!!
  int n = nums.size();
  int cnt = 0;
  int left = 0;
  int right = 0;
  int sum = nums[0];

  while(right < n) {
    // shrink
    while(left <= right && sum > k) {
      sum -= nums[left];
      left++;
    }

    if(sum == k) cnt++;

    right++; // move to add

    // expand
    if(right < n) {
      sum += nums[right];
    }
  }

  return cnt;
}


int main() {
  vector<int> nums = {3, 1, 2, 4};
  int k = 6;

  // cout << "Total subarrays with sum k is : " << totalSubarraysBrute(nums, k) << endl;

  // cout << "Total subarrays with sum k is : " << totalSubarraysBetter(nums, k) << endl;

  cout << "Total subarrays with sum k is : " << totalSubarraysOptimal(nums, k) << endl;
}