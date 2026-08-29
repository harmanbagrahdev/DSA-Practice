// Given an array of intervals where intervals[i] = [ start[i], end[i] ], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n * log(n) ) + O(2 * n)
// S = O(n)
vector<vector<int>> mergeIntervals(vector<vector<int>>& nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end()); // n * log(n)
  vector<vector<int>> ans;

  // T = O(2 * n)
  for(int i = 0; i < n; i++) {
    int start = nums[i][0];
    int end = nums[i][1];

    if(!ans.empty() && end <= ans.back()[1] ) continue;
    
    for(int j = i+1; j < n; j++) {
      if(nums[j][0] <= end) end = max(end, nums[j][1]);
      else break; // as sorted so after that we will find no pair
    }
    ans.push_back({start, end});
  }

  return ans;
}


// Optimalsolution
// T = O(n) + O(n * log(n) )
// S = O(n)
vector<vector<int>> mergeIntervalsOptimal(vector<vector<int>>& nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end()); // n * log(n)
  vector<vector<int>> ans;

  // T = O(2 * n)
  for(int i = 0; i < n; i++) {
    if(ans.empty() || nums[i][0] > ans.back()[1]) {
      ans.push_back(nums[i]);
    }
    
    else {
      ans.back()[1] = max(ans.back()[1], nums[i][1]);
    }
  }

  return ans;
}


int main() {
  vector<vector<int>> nums = { {1,3},{2,6},{8,10},{15,18} };

  // vector<vector<int>> result = mergeIntervals(nums);

  vector<vector<int>> result = mergeIntervalsOptimal(nums);

  for(auto row : result) {
    for(auto value : row) {
      cout << value << " ";
    }
    cout << endl;
  }
  cout << endl;
}