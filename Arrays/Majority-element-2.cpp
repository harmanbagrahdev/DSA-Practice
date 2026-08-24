// Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. The output can be returned in any order.

#include <bits/stdc++.h>
using namespace std;

// Better Solution : My solution
// T = O(2*n)
// S = O(n) --> in worst case
vector<int> majorityElementBetter(vector<int>& nums) {
  int n = nums.size();
  unordered_map<int, int> mpp;
  vector<int> ans;

  for(int i = 0; i < n; i++) {
    mpp[nums[i]]++;
  }

  for(auto& [key, value] : mpp) {
    if(value > n/3) ans.push_back(key);
  }
  return ans;
}

int linearSearch(vector<int>& nums, int& num) {
  int cnt = 0;
  for(int i = 0; i < nums.size(); i++) {
    if(nums[i] == num) cnt++;
  }
  return cnt;
}

// Brute solution
// T = O(n^2)
// S = O(1) ---> auxilliary space
vector<int> majorityElementBrute(vector<int>& nums) {
  int n = nums.size();
  vector<int> ans(2);
  int j = 0;

  for(int i = 0; i < n; i++) {
    if(ans.size() == 0 || ans[0] != nums[i]) {
      int cnt = linearSearch(nums, nums[i]);
      if(cnt > n/3 && j < 2) {
        ans[j] = nums[i];
        j++;
      }
    }
  }
  
  return ans;
}

int main() {
  vector<int> nums = {1,1,1,3,3,2,2,2};

  // vector<int> result = majorityElement(nums);

  vector<int> result = majorityElementBrute(nums);
  for(auto i : result) {
    cout << i << " ";
  }
  cout << endl;
}