// You're given an sorted array arr of n integers and an integer x.
// Find the floor and ceiling of x in arr[0..n-1].
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

#include <bits/stdc++.h>
using namespace std;

// T = O(log(n))
// S = O(1)
int floorArr(vector<int>& nums, int& x) {
  int n = nums.size();
  int low = 0;
  int high = n-1;
  int ans = -1;

  while(low <= high) {
    int mid = (low + high) / 2;

    if(x >= nums[mid]) {
      ans = nums[mid];
      low = mid+1;
    }
    else {
      high = mid-1;
    }
  }

  return ans;
}

// T = O(log(n))
// S = O(1)
int ceilArr(vector<int>& nums, int& x) {
  int n = nums.size();
  int low = 0;
  int high = n-1;
  int ans = -1;

  while(low <= high) {
    int mid = (low + high) / 2;

    if(x <= nums[mid]) {
      ans = nums[mid];
      high = mid-1;
    }
    else {
      low = mid+1;
    }
  }

  return ans;
}

int main() {
  vector<int> nums = {3, 4, 4, 7, 8, 10};
  int x = 5;

  cout << floorArr(nums, x) << endl;
  cout << ceilArr(nums, x) << endl;
}