// Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key.
// If the target is not found then return -1.
// Note: Consider 0 based indexing

#include <bits/stdc++.h>
using namespace std;

// My Solution
// T = O(n)
// S = O(1)
vector<int> lastOccurence(vector<int>& nums, int& target) {
  int n = nums.size();
  vector<int> ans = {-1, -1};

  for (int i = 0; i < n; i++) {
    if (nums[i] == target) {
      ans[0] = i;
      break;
    }
  }
  
  for(int i = n-1; i >= 0; i--) {
    if(nums[i] == target) {
      ans[1] = i;
      break;
    }
  }

  return ans;
}

// Optimal solution
// T = O(log(n))
// S = O(1)
// int lastOccurence(vector<int>& nums, int& target) {
//   int n = nums.size();
//   int low = 0;
//   int high = n-1;

//   while(low <= high) {

//   }

//   return -1;
// }

int main() {
  vector<int> nums = {3, 4, 13, 13, 13, 20, 40};
  int target = 13;

  // cout << lastOccurence(nums, target) << endl;

  vector<int> ans = lastOccurence(nums, target);
  for(auto i : ans) {
    cout << i << " ";
  } cout << endl;
}