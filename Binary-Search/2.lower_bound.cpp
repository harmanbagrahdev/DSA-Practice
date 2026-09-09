// Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

// The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

// The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

#include <bits/stdc++.h>
using namespace std;

// T = O(n)
// S = O(1)
int lowerBoundBrute(vector<int>& nums, int x) {
  int n = nums.size();

  for(int i = 0; i < n; i++) {
    if(nums[i] >= x) return i;
  }

  return n;
}

// T = O(log(n))
// S = O(1)
int lowerBoundOptimal(vector<int>& nums, int x) {
  int n = nums.size();
  int low = 0, high = n-1;
  int ans = n;
  
  while(low <= high) {
    int mid = (low + high) / 2;

    if(nums[mid] >= x) {
      ans = mid;
      high = mid - 1;
    }
    else {
      low = mid+1;
    }
  }

  return ans;
}


int main() {
  vector<int> nums = {3,5,8,15,19};
  
  // cout << lowerBoundBrute(nums, 9) << endl;
  
  // cout << lowerBoundOptimal(nums, 9) << endl;

  // Or we can just use this :
  auto lb = lower_bound(nums.begin(), nums.end(), 9) - nums.begin(); // this returns iterator so to get index we just subtract starting iterator!
  cout << lb << endl;
}