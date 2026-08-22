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

// Optimal solution : do visit logic and do dry run if you can't recall in future!
// T = O(n * log(n) )
// S = O(n)
int totalSubarraysOptimal(vector<int>& nums, int k) {
  int n = nums.size();
  int cnt = 0;
  int preSum = 0;
  unordered_map<int, int> mpp;
  mpp[0] = 1;

  for(int i = 0; i < n ; i++) {
    preSum += nums[i];
    int rem = preSum - k;
    cnt += mpp[rem];
    mpp[preSum] += 1;
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