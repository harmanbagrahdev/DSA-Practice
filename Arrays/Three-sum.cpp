// Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[i], arr[j], arr[k]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

// Find triplets that add upto zero

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n^3 * log(no. of unique elements) ) + O(n)
// S = O(number of triplets)
set<vector<int>> threeSumBrute(vector<int>& nums) {
  int n = nums.size();
  set<vector<int>> ans; // S = O(n)

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      for(int k = j+1; k < n; k++) {
        if(nums[i] + nums[j] + nums[k] == 0) {
          vector<int> temp = {nums[i], nums[j], nums[k]}; // S = O(3) --> constant
          sort(temp.begin(), temp.end()); // T = O(n)
          ans.insert(temp); // T = O(log(n))
        }
      }
    }
  }

  return ans;
}

// Better solution
// T = O(n^2 * log(size of set) )
// S = O(2 * number of triplets)
vector<vector<int>> threeSumBetter(vector<int>& nums) {
  int n = nums.size();
  set<vector<int>> st; // collecting here
  
  for(int i = 0; i < n; i++) {
    set<int> hash;
    for(int j = i+1; j < n; j++) {
      int el = -(nums[i] + nums[j]);
      if(hash.find(el) != hash.end() ) { // present
        vector<int> temp = {nums[i], el, nums[j]}; // store
        sort(temp.begin(), temp.end()); // sort
        st.insert(temp); // collect
      }
      else {
        hash.insert(nums[j]);
      }
    }
  }

  vector<vector<int>> ans(st.begin(), st.end()); // to return answer
  
  return ans;
}

// Optimal Solution
// T = O()
// S = O()
vector<vector<int>> threeSumOptimal(vector<int>& nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  
  for(int i = 0; i < n; i++) {
    int j = i + 1;
    int k = n-1-i;
    while(j <= k) {
      if(nums[i] + nums[j] + nums[k] == 0) {
        ans.push_back({nums[i], nums[j], nums[k]});
        j++;
        k--;
      }
    }
  }
  
  return ans;
}

int main() {
  vector<int> nums = {-1,0,1,2,-1,-4};
  
  // set<vector<int>> result = threeSumBrute(nums);

  // vector<vector<int>> result = threeSumBetter(nums);

  vector<vector<int>> result = threeSumOptimal(nums);
  for(auto row : result) {
    for(auto value : row) {
      cout << value << " ";
    }
    cout << endl;
  } cout << endl;
}