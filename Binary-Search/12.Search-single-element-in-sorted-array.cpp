// Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array

#include <bits/stdc++.h>
using namespace std;

// Brute force is just run a linear search comparing adjacent elements or we can xor the array and we will be left with element that occurs only once !

// Optimal solution
// T = O(log(n))
// S = O(1)
int singleEl(vector<int>& nums) {
  int n = nums.size();
  int low = 0, high = n-1;
  
  if(n == 1) return nums[0];
  else if(nums[0] != nums[1]) return nums[0];
  else if(nums[n-1] != nums[n-2]) return nums[n-1];

  while(low <= high) {
    int mid = (low + high) / 2;

    if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
    
    if( (mid % 2 == 0 && nums[mid] == nums[mid+1]) || (mid % 2 == 1 && nums[mid] == nums[mid-1]) ) low = mid+1;

    else high = mid-1;
  }

  return -1;
}

int main() {
  vector<int> nums = {1,1,2,2,3,3,4,5,5,6,6};

  cout << singleEl(nums) << endl;
}