#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n^2)
// S = O(1)
int maxProductBrute(vector<int>& nums) {
  int n = nums.size();
  int maxProd = nums[0];

  for(int i = 0; i < n; i++) {
    int product = 1;
    for(int j = i; j < n; j++) {
      product *= nums[j];

      maxProd = max(maxProd, product);
    }
  }

  return maxProd;
}

int main() {
  vector<int> nums = {1,2,3,4,5,0};

  cout << maxProductBrute(nums) << endl;
}