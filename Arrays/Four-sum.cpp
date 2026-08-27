// Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.
// Note: a, b, c and d are also distinct and lies between 0 to n-1 (both inclusive).

#include <bits/stdc++.h>
using namespace std;

// Brute solution
// T = O(n^4)
// S = O(number of quads)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
  int n = nums.size();
  set<vector<int>> st;

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      for(int k = j+1; k < n; k++) {
        for(int l = k+1; l < n; l++) {
          long long sum = nums[i] + nums[j] + nums[k] + nums[l];
          if(sum == target) {
            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]}; // S = O(4)
            sort(temp.begin(), temp.end());
            st.insert(temp);
          }
        }
      }
    }
  }

  vector<vector<int>> ans(st.begin(), st.end());

  return ans;
}

// Better solution
// T = O(n^3)
// S = O(number of quads)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
  int n = nums.size();
  vector<vector<int>> ans;

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      for(int k = j+1; k < n; k++) {
        for(int l = k+1; l < n; l++) {
          int sum = nums[i] + nums[j] + nums[k] + nums[l];
          if(sum == target) {
            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]}; // S = O(4)
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
      }
    }
  }
}

  return ans;
}

int main() {
  vector<int> nums = {1,0,-1,0,-2,2};
  int target = 0;

  vector<vector<int>> result = fourSum(nums, target);
  for(auto row : result) {
    for(auto value : row) {
      cout << value << " ";
    }
    cout << endl;
  }
  cout << endl;
}