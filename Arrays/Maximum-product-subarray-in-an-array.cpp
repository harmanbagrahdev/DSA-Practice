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

// Optimal solution 1
// T = O(n)
// S = O(1)
int maxProductOptimal_1(vector<int>& nums) {
  int n = nums.size();
  int product1 = 1;
  int product2 = 1;
  int ans = INT16_MIN;

  for(int i = 0; i < n; i++) {
    if(product1 == 0) product1 = 1;
    if(product2 == 0) product2 = 1;
    product1 *= nums[i];
    product2 *= nums[(n-1) - i];

    ans = max(ans, max(product1, product2));
  }
  return ans;
}

int main() {
  vector<int> nums = {-2,0,-1};

  // cout << maxProductBrute(nums) << endl;

  cout << maxProductOptimal_1(nums) << endl;
}