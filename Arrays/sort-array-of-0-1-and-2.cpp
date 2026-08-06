// Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order. The sorting must be done in-place, without making a copy of the original array.

#include <bits/stdc++.h>
using namespace std;

// Brute force
void sortArray(vector<int>& nums) {
  int n = nums.size();
  int zeroes = 0, ones = 0, twos = 0;

  for(int i = 0; i < n; i++) {
    if(nums[i] == 0) zeroes++;
    else if(nums[i] == 1) ones++;
    else if(nums[i] == 2) twos++;
  }

  int index = 0;
  while(zeroes--) nums[index++] = 0;
  while(ones--) nums[index++] = 1;
  while(twos--) nums[index++] = 2;


  for(auto i : nums) {
    cout << i << " ";
  } cout << endl;
}

int main() {
  vector<int> nums = {0,0,1,2,1,0,1,2};

  sortArray(nums);
}