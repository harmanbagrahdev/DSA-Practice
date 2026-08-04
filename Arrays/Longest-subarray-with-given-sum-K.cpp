// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

#include <bits/stdc++.h>
using namespace std;
// -----------------------------------------------------------
// ----> Subarray : elements from contiguous memory loactions
// -----------------------------------------------------------

// My Solution : wrong
// sorted array is required for this function
// T = O(n)
// S = O(1)
// but we also need to consider sorting function's time and space complexity

// int longestSubarray(vector<int>& arr, int n) {
//   int sum = 0;

//   for(int i = 0; i < arr.size(); i++) {
//     if(sum == n) {
//       return i;
//     }
//     sum += arr[i];
//   }
//   return 0;
// }

// brute --> generate all subarrays and solve
// T = O(n^3) --> nearly
// S = O(1)
int longestSubarrayBrute(vector<int>& arr, int K) {
  int maxLength = 0;
  
  // Create subarrays
  for(int i = 0; i < arr.size(); i++) { // start index
    
    for(int j = i; j < arr.size(); j++) { // end index
      int sum = 0;
      for(int k = i; k <= j; j++) { // sum
        sum += arr[k];
      }

      if(sum == K) maxLength = max(maxLength, j-i+1);
    }
  }

  return maxLength;
}

// Optimized Brute Force
// T = O(n^2)
// S = O(1)
int longestSubarrayBrute2(vector<int>& arr, int k) {
  int maxLength = 0;
  
  // Create subarrays
  for(int i = 0; i < arr.size(); i++) { // start index
    
    int sum = 0;
    for(int j = i; j < arr.size(); j++) { // end index
      sum += arr[j]; // summation of every element during iteration

      if(sum == k) maxLength = max(maxLength, j-i+1);
    }
  }

  return maxLength;
}

// Better : By hash map (pre sum method)
// T = O( n * log(n) ), or 
// O(n^2) in worst case for unordered map
// S = O(n) --> worst case
// for positives and zeroes 
// In case of array containing positives and negatives and zeroes this is the optimal solution!
int longestSubarrayBetter(vector<int>& arr, long long k) {
  map<long long, int> preSumMap;
  int maxLength = 0;
  long long sum = 0;

  for(int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    if(sum == k) {
      maxLength = max(maxLength, i+1);
    }

    long long rem = sum - k;
    if(preSumMap.find(rem) != preSumMap.end()) {
      int len = i - preSumMap[rem];
      maxLength = max(maxLength, len);
    }

    if(preSumMap.find(sum) != preSumMap.end()) {
    preSumMap[sum] = i;
    }
  }

  return maxLength;
}

// Optimal Solution ---> If array contains positives and zeroes only (2 pointer and greedy approach)
// T = O(2*n)
// S = O(1)
int longestSubarrayOptimal(vector<int>& arr, int k) {
  int left = 0;
  int right = 0;
  int maxLength = 0;
  int n = arr.size();
  long long sum = arr[0];

  while(right < n) {
    // shrink when sum exceeds
    while(left <= right && sum > k) {
      sum -= arr[left];
      left++;
    }

    if(sum == k) {
      maxLength = max(maxLength, right - left + 1);
    }

    right++; // move and add

    if(right < n) { // check before adding
      sum += arr[right];
    }
  }
  
  return maxLength;
}

int main() {
  vector<int> arr = {10, 5, 2, 7, 1, 9};
  int k = 15;
  
  // cout << longestSubarray(arr, k) << endl;

  // cout << longestSubarrayBrute(arr, k) << endl;

  // cout << longestSubarrayBrute2(arr, k) << endl;

  // cout << longestSubarrayBetter(arr, k) << endl;

  cout << longestSubarrayOptimal(arr, k) << endl;

}