// Given an array nums of n integers.
// Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &nums, int num) { // T = O(n)
  int n = nums.size();

  for(int i = 0; i < n; i++) {
    if(nums[i] == num) return true;
  }
  return false;
}

// Brute Force
// T = O(n^2)
// S = O(1)
int longestSequence(vector<int> &nums) {
  int n = nums.size();
  int longest = 1;
  
  if(nums.empty()) return 0;

  for(int i = 0; i < n; i++) {
    int el = nums[i];
    int cnt = 1;

    while(linearSearch(nums, el+1) == true) {
      el++;
      cnt++;
    }

    longest = max(longest, cnt);
  }
  
  return longest;
}

// Better Solution
// T = O(n) + O(n * log(n) ) --> for sorting
// S = O(1)
int longestSequenceBetter(vector<int>& nums) {
  int n = nums.size();
  int curCnt = 0;
  int lastSmaller = INT16_MIN;
  int longest = 1;
  sort(nums.begin(), nums.end());

  if(nums.empty()) return 0;

  for(int i = 0; i < n; i++) {
    if(nums[i] - 1 == lastSmaller) {
      curCnt++;
    }
    else if(nums[i] != lastSmaller) {
      curCnt = 1;
    }

    lastSmaller = nums[i];
    longest = max(curCnt, longest);
  }

  return longest;
}

// Optimal solution in case of no collisions
// T = O(n)
// S = (n) --> in worst case when all elements are unique
int longestSequenceOptimal(vector<int>& nums) {
  int longest = 1;

  if(nums.empty()) return 0;

  unordered_set<int> st;
  for(int i = 0; i < nums.size(); i++) {
    st.insert(nums[i]);
  }

  for(auto it : st) {
    if(st.find(it - 1) == st.end()) {
      int cnt = 1;
      int firstEl = it;

      while(st.find(firstEl + 1) != st.end()) {
        firstEl++;
        cnt++;
      }
      longest = max(longest, cnt);
    }
  }

  return longest;
}

int main() {
  vector<int> nums = {1,2,6,7,8};

  // cout << longestSequence(nums) << endl;

  // cout << longestSequenceBetter(nums) << endl;

  cout << longestSequenceOptimal(nums) << endl;
}