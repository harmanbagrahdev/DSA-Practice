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
// T = O(n^2)
// S = O(1) --> auxilliary space
vector<vector<int>> threeSumOptimal(vector<int>& nums) {
  int n = nums.size();
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end()); // T = n * log(n)

  for(int i = 0; i < n-1; i++) { // T = O(n)
    if(i > 0 && nums[i] == nums[i-1]) continue;

    int j = i+1;
    int k = n-1;

    while(j < k) { // T = O(n)
        int sum = nums[i] + nums[j] + nums[k];

        if(sum == 0) {
          ans.push_back({nums[i], nums[j], nums[k]});
          j++;
          k--;
          while(j < k && nums[j] == nums[j-1]) j++; // these two loops are to check if elements are same!    T = nearly constant
          while(j < k && nums[k] == nums[k+1]) k--;
        }

        else if(sum < 0) j++;
        else if(sum > 0) k--;
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

  cout << "end\n";
}