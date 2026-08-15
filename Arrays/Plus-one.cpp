#include <bits/stdc++.h>
using namespace std;

// My solution : fails if there's only one digit in our array
// T = O(3*n)
// S = O(1)
vector<int> plusOneBuggy(vector<int>& nums) {
  int num = 0;

  for(int i = 0; i < nums.size(); i++) {
    num = num * 10 + nums[i];
  }
  num += 1;

  int index = 0;
  while(num != 0) {
    int digit = num % 10;
    nums[index] = digit;
    index++;
    num /= 10;
  }

  int start = 0, last = nums.size() - 1;
  while(start <= last) {
    swap(nums[start],nums[last]);
    start++;
    last--;
  }

  return nums;
}

// T = O(n)
// S = O(1)
vector<int> plusOne(vector<int>& nums) {
  int n = nums.size();

  for(int i = n-1; i >= 0; i--) {
    if(nums[i] < 9) {
      nums[i]++;
      return nums;
    }

    nums[i] = 0; // if digit is 9 (loop follows by carrying)
  }

  nums.insert(nums.begin(), 1);

  return nums;
}

int main() {
  vector<int> nums = {4,9,1};

  plusOne(nums);

  for(auto i : nums) {
    cout << i << " ";
  } cout << endl;
}