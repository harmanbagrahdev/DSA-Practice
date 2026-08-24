// Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. The output can be returned in any order.

#include <bits/stdc++.h>
using namespace std;

// Better Solution : My solution
// T = O(n * O(1)) {unordered_map} + O(n)
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

// Improved Better Solution
// T = O(n * O(1)) {unordered_map}
// S = O(n) --> in worst case
vector<int> majorityElementBetter2(vector<int>& nums) {
  int n = nums.size();
  unordered_map<int, int> mpp;
  vector<int> ans;
  int atleast = (int)(n/3) + 1;

  for(int i = 0; i < n; i++) {
    mpp[nums[i]]++;

    // to get rid of second iteration!
    if(mpp[nums[i]] == atleast) ans.push_back(nums[i]);

    if(ans.size() == 2) break;
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
  vector<int> ans;

  for(int i = 0; i < n; i++) {
    if(ans.size() == 0 || ans[0] != nums[i]) {
      int cnt = linearSearch(nums, nums[i]);
      if(cnt > n/3 && ans.size() < 2) {
        ans.push_back(nums[i]);
      }
    }
  }
  
  return ans;
}

// T = O(2*n)
// S = O(1) ---> auxilliary space
vector<int> majorityElementOptimal(vector<int>& nums) {
  int n = nums.size();
  int cnt1 = 0, cnt2 = 0;
  int el1, el2;
  vector<int> ans;

  for(int i = 0; i < n; i++) {
    if(cnt1 == 0 && nums[i] != el2) {
      el1 = nums[i];
      cnt1 = 1;
    }
    else if(cnt2 == 0&& nums[i] != el1) {
      el2 = nums[i];
      cnt2 = 1;
    }

    else if(el1 == nums[i]) cnt1++;
    else if(el2 == nums[i]) cnt2++;

    else {
      cnt1--;
      cnt2--;
    }
  }

  int atleast = (int)(n/3) + 1;
  int check1 = 0, check2 = 0;
  
  for(int j = 0; j < n; j++) {
    if(nums[j] == el1) check1++;
    else if(nums[j] == el2) check2++;
  }
  
  if(check1 >= atleast && ans.size() < 2) ans.push_back(el1);
  if(check2 >= atleast && ans.size() < 2) ans.push_back(el2);

  return ans;
}

int main() {
  vector<int> nums = {1,1,1,3,3,2,2,2};

  // vector<int> result = majorityElementBetter(nums);

  // vector<int> result = majorityElementBrute(nums);

  vector<int> result = majorityElementOptimal(nums);
  for(auto i : result) {
    cout << i << " ";
  }
  cout << endl;
}