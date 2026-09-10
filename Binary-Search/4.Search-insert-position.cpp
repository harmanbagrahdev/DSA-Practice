// You are given a sorted array arr of distinct values and a x value x. You need to search for the index of the x value in the array.

#include <bits/stdc++.h>
using namespace std;

// My solution : Brute Force
// T = O(n)
// S = O(1)
int searchPosBrute(vector<int>& nums, int x) {
  int n = nums.size();
  int pos = 0;

  if(n == 1) {
    if(x > nums[0]) return 1;
    else return 0;
  }

  for(int i = 0; i < n-1; i++) {
    if(x > nums[i] && x < nums[i+1]) pos = i+1;
    else if(x == nums[i]) pos = i;
    else if(x < nums[0]) pos = 0;
    else if(x > nums[n-1]) pos = (n-1) + 1;
    else if(x == nums[n-1]) pos = n-1;
  }

  return pos;
}

// Optimal solution
// Just lower bound algorithm will do it!
// T = O(log(n))
// S = O(1)
int searchPosOptimal(vector<int>& nums, int x) {
  int n = nums.size();
  int pos = n; // if x is greater than all elements
  int low = 0, high = n-1;

  while(low <= high) {
    int mid = (low + high) / 2;

    if(x <= nums[mid]) {
      pos = mid;
      high = mid-1;
    }
    else {
      low = mid+1;
    }
  }

  return pos;
}


int main() {
  vector<int> nums = {3,5,8,15,19};

  // cout << searchPosBrute(nums, 20) << endl;

  cout << searchPosOptimal(nums, 2) << endl;
}