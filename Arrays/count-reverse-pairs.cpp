// Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T = O(n^2)
// S = O(1)
int countPairs(vector<int> &nums) {
  int n = nums.size();
  int cnt = 0;

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      if(nums[i] > 2 * nums[j]) cnt++;
    }
  }
  return cnt;
}

int main() {
  vector<int> nums = {1,3,2,3,1};

  cout << countPairs(nums) << endl;
}