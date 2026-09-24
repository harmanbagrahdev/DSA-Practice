// You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. Each painter takes B units of time to paint 1 unit of board.
// You must assign boards to painters such that:

// Each painter paints only contiguous segments of boards.
// No board can be split between painters.
// The goal is to minimize the time to paint all boards.
// Return the minimum time required to paint all boards modulo 10000003.

#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
// T = O(log(n))
// S = O(1)
int paint(int A, int B, vector<int>& C) {
  const long long Mod = 1e7 + 3;
  long long low = *max_element(C.begin(), C.end());
  long long high = accumulate(C.begin(), C.end(), 0LL);

  while(low < high) {
    long long mid = (low + high) / 2;
    int painters = 1;
    long long curr = 0;

    for(auto x : C) {
      if(curr + x > mid) {
        painters++;
        curr = x;
      }
      else curr += x;
    }

    if(painters <= A) high = mid;
    else low = mid + 1;
  }

  return (low % Mod) * (B % Mod) % Mod;
}

// Similar question :
// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
// Return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

int splitArray(vector<int>& nums, int k) {
  long long low = *max_element(nums.begin(), nums.end());
  long long high = accumulate(nums.begin(), nums.end(), 0LL);

  while (low < high) {
      long long mid = (low + high) / 2;
      int subArrCnt = 1;
      long long curr = 0;

      for (auto x : nums) {
          if (curr + x > mid) {
            subArrCnt++;
              curr = x;
          } else
              curr += x;
      }

      if (subArrCnt <= k)
          high = mid;
      else
          low = mid + 1;
  }

  return low;
}

int main() {
  vector<int> C = {5, 10, 30, 20};
  int A = 3, B = 2;

  // cout << paint(A, B, C) << endl;

  vector<int> nums = {7,2,5,10,8};
  int k = 2;

  cout << splitArray(nums, k) << endl;
}