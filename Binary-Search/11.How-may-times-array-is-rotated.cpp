// Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.

#include <bits/stdc++.h>
using namespace std;

// Optimal solution
// T = O(log(n))
// S = O(1)
int rotated(vector<int>& nums) {
  int low = 0, high = nums.size()-1;

  while(low < high) {
    int mid = (low + high) / 2;

    if(nums[mid] > nums[high]) low = mid + 1;
    else high = mid;
  }

  return low;
}

int main() {
  vector<int> nums = {4,5,6,7,0,1,2,3};

  cout << rotated(nums) << endl;
}