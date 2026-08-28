// Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.
// Note: a, b, c and d are also distinct and lies between 0 to n-1 (both inclusive).

#include <bits/stdc++.h>
using namespace std;

// Brute solution
// T = O(n^4 * log(n) )
// S = 2 * O(number of quads)
vector<vector<int>> fourSumBrute(vector<int>& nums, int target) {
  int n = nums.size();
  set<vector<int>> st;

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      for(int k = j+1; k < n; k++) {
        for(int l = k+1; l < n; l++) {
          long long sum = nums[i] + nums[j];
          sum += nums[k];
          sum += nums[l];
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
// T = O(n^3 * log(n) )
// S = 2 * O(number of quads)
vector<vector<int>> fourSumBetter(vector<int>& nums, int target) {
  int n = nums.size();
  set<vector<int>> st;

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      set<long long> hashSet;
      for(int k = j+1; k < n; k++) {
        long long sum3 = nums[i] + nums[j] + nums[k];
        int el = target - sum3;
        if(hashSet.find(el) != hashSet.end()) {
            vector<int> temp = {nums[i], nums[j], nums[k], (int)el}; // S = O(4)
            sort(temp.begin(), temp.end());
            st.insert(temp);
        }
        hashSet.insert(nums[k]);
      }
    }
  }

  vector<vector<int>> ans(st.begin(), st.end());

  return ans;
}

// Optimal Solution
// T = O()
// S = O()
vector<vector<int>> fourSumOptimal(vector<int>& nums, int target) {
  int n = nums.size();
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());

  for(int i = 0; i < n; i++) {
    if(i > 0 && nums[i] == nums[i-1]) continue;
    
    for(int j = i+1; j < n; j++) {
      if(j > i+1 && nums[j] == nums[j-1]) continue;
      int k = j+1;
      int l = n-1;
  
      while(k < l) {
        long long sum = nums[i] + nums[j];
        sum += nums[k];
        sum += nums[l];
  
        if(sum > target) l--;
        else if(sum < target) k++;
        else {
          vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
          ans.push_back(temp);
          k++;
          l--;
          while(k < l && nums[k] == nums[k-1]) k++; 
          while(k < l && nums[l] == nums[l+1]) l--; 
        }
      }
    }
  }

  return ans;
}

int main() {
  vector<int> nums = {1,0,-1,0,-2,2};
  int target = 0;

  // vector<vector<int>> result = fourSumBrute(nums, target);

  // vector<vector<int>> result = fourSumBetter(nums, target);

  vector<vector<int>> result = fourSumOptimal(nums, target);
  for(auto row : result) {
    for(auto value : row) {
      cout << value << " ";
    }
    cout << endl;
  }
  cout << endl;
}