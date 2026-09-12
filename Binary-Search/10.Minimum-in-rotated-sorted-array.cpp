// Given an integer array arr of size N, sorted in ascending order (with distinct values), the array is rotated at any index which is unknown. Find the minimum element in the array.

#include <bits/stdc++.h>
using namespace std;

// Brute
// T = O(n)
// S = O(1)
int findMinBrute(vector<int>& nums) {
  int mini = nums[0];

  for(int i = 0; i < nums.size(); i++) {
    mini = min(mini, nums[i]);
  }

  return mini;
}

// Optimal
// T = O(log(n))
// S = O(1)
int findMinOptimal(vector<int>& nums) {
  int low = 0, high = nums.size() - 1;

  while(low < high) {
    int mid = (low + high) / 2;

    if(nums[mid] > nums[high]) low = mid+1;
    else high = mid;
  }

  return nums[low];
}

int main() {
  vector<int> nums = {4,5,6,7,0,1,2,3};
  
  // cout << findMinBrute(nums) << endl;

  cout << findMinOptimal(nums) << endl;
}