// Given an integer array nums, return a list of all the leaders in the array.

// A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T = O(n^2)
// S = O(n) --> in worst case (to store the answer)
vector<int> leaders(vector<int>& nums) {
  int n = nums.size();
  vector<int> ans;
  
  for(int i = 0; i < n; i++) {
    int maxi = nums[i];

    for(int j = i+1; j < n; j++) {
      maxi = max(maxi, nums[j]);
    }

    if(maxi == nums[i]) {
      ans.push_back(nums[i]);
    }
  }

  return ans;
}

// Optimal solution
// T = O(n) + O(n)
// S = O(n) --> in worst case (to store the answer)
vector<int> leadersOptimal(vector<int>& nums) {
  int n = nums.size();
  vector<int> ans;
  ans.push_back(nums[n-1]);

  int maxi = nums[n-1];

  for(int i = n-2; i >= 0; i--) {
    if(nums[i] > maxi) {
      maxi = nums[i];
      ans.push_back(maxi);
    }
  }

  reverse(ans.begin(), ans.end()); // O(n)

  return ans;
}

int main() {
  vector<int> nums = {4, 7, 1, 0};

  // vector<int> ans = leaders(nums);

  vector<int> ans = leadersOptimal(nums);

  for(auto i : ans) {
    cout << i << " ";
  } cout << endl;
}