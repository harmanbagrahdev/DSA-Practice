// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.

#include <bits/stdc++.h>
using namespace std;

// Brute
// T = O(n)
// S = O(1)
int kthMissing(vector<int>& nums, int k) {
  int n = nums.size();
  int cnt = 0;
  int j = 1; // comparing element
  int i = 0; // current element

  while(cnt < k) {
    if(i < n && nums[i] == j) i++;

    else {
      cnt++;
      if(cnt == k) return j;
    }

    j++;
  }

  return j;
}

// Better
// T = O(n)
// S = O(1)
int kthMissingBetter(vector<int>& nums, int k) {
  for(auto i : nums) {
    if(i <= k) k++;
    else break;
  }

  return k;
}

// Optimal
// T = O(log(n))
// S = O(1)
int kthMissingOptimal(vector<int>& nums, int k) {
  int left = 1;
  int right = nums.size() - 1;

  while(left <= right) {
    int mid = left + (right - left) / 2;

    // element in array - actual element that should be present at that index = number of elements missing
    int missing = nums[mid] - (mid+1);

    if(missing < k) left = mid+1;
    else right = mid-1;
  }

  return left + k; // or (right + 1) + k
}

int main() {
  vector<int> nums = {2, 3, 4, 7, 11};
  int k = 5;

  // cout << kthMissing(nums, k) << endl;

  cout << kthMissingBetter(nums, k) << endl;

  // cout << kthMissingOptimal(nums, k) << endl;
}