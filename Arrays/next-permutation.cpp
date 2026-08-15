// Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
// If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n! * nlog(n) )
// S = O(n!)
vector<int> nextPermutation(vector<int>& nums) {
  vector<int> original = nums; // to compare after
  sort(nums.begin(), nums.end()); // sort to start permutations
  vector<vector<int>> store;

  do {
    store.push_back(nums);
  } while( next_permutation(nums.begin(), nums.end()) );

  for(int i = 0; i < store.size(); i++) {
    if(store[i] == original) {
      if(i == store.size() - 1) { // if last element return first permutation
        return store[0];
      }
      
      return store[i+1];
    }
  }

  return nums;
}

// Optimal Solution
// T = O(3 * n)
// S = O(1) --> auxilliary space
vector<int> nextPermutationOptimal(vector<int>& nums) {
  int n = nums.size();
  int index = -1;

  // find breakpoint
  for(int i = n-2; i >= 0; i--) { // iterate from last second to first to find dictionary order
    if(nums[i] < nums[i+1]) {
      index = i;
      break;
    }
  }

  if(index == -1) {
    reverse(nums.begin(), nums.end());
    return nums;
  }

  for(int i = n-1; i >= 0; i--) {
    if(nums[i] > nums[index]) {
      swap(nums[i], nums[index]);
      break;
    }
  }

  reverse(nums.begin() + index + 1, nums.end()); // T = O(n) in worst case

  return nums;
}

int main() {
  vector<int> nums = {1,3,2};

  // vector<int> ans =  nextPermutation(nums);

  vector<int> ans =  nextPermutationOptimal(nums);
  for(auto i : ans) {
    cout << i << " ";
  } cout << endl;
}