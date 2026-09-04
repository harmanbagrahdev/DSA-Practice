#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n^2)
// S = O(1)
vector<int> solutionBrute(vector<int>& nums) {
  int n = nums.size();
  int repeating = -1;
  int missing = -1;

  for(int i = 1; i <= n; i++) {
    int cnt = 0;

    for(int j = 0; j < n; j++) {
      if(nums[j] == i) cnt++;
    }

    if(cnt == 2) repeating = i;
    else if(cnt == 0) missing = i;
    
    if(missing != -1 && repeating != -1) break;
  }
  return {repeating, missing};
}

// Better Solution
// T = O(2*n)
// S = O(n)
vector<int> solutionBetter(vector<int>& nums) {
  int n = nums.size();
  int repeating = -1;
  int missing = -1;

  vector<int> hashArr(n+1, 0);

  for(int i = 0; i < n; i++) {
    hashArr[nums[i]]++;
  }

  for(int j = 1; j <= n; j++) {
    if(hashArr[j] == 0) missing = j;
    else if(hashArr[j] == 2) repeating = j;
    
    if(missing != -1 && repeating != -1) break;
  }

  return {repeating, missing};
}

// Optimal Solution
// T = O(n)
// S = O(1)
vector<int> solutionOptimal_1(vector<int>& nums) {
  long long n = nums.size();
  long long repeating = -1; // X
  long long missing = -1; // Y

  long long sum = (n * (n+1)) / 2;
  long long squareSum = (n * (n+1) * (2*n + 1) ) / 6;

  long long arrSum = 0, squareArrSum = 0;

  for(int i = 0; i < n; i++) {
    arrSum += nums[i];
    squareArrSum += (long long)nums[i] * (long long)nums[i];
  }

  long long sumDiff = arrSum - sum; // X - Y
  long long squareSumDiff = squareArrSum - squareSum; // X^2 - Y^2 = (X+Y) * (X-Y) = value

  squareSumDiff = squareSumDiff / sumDiff;
  repeating = (squareSumDiff + sumDiff) / 2;
  missing = repeating - sumDiff;

  return {(int)repeating, (int)missing};
}

// Optimal Solution : with xor logic
// T = O(n)
// S = O(1)
vector<int> solutionOptimal_2(vector<int>& nums) {
  int n = nums.size();
  int xr = 0;

  for(int i = 0; i < n; i++) {
    xr = xr ^ nums[i];
    xr = xr ^ (i+1);
  }

  int bitNum = 0;
  while(1) {
    if((xr & (1 << bitNum)) != 0) break;
    else bitNum++;
  }
  // bitNum logic shortcut
  // int bitNum = xr & ~(xr -1);

  int zeroGp = 0;
  int oneGp = 0;

  for(int i = 0; i < n; i++) {
    if((nums[i] & (1 << bitNum)) == 0) zeroGp = zeroGp ^ nums[i];
    else oneGp = oneGp ^ nums[i];
  }

  for(int i = 1; i <= n; i++) {
    if((i & (1 << bitNum)) == 0) zeroGp = zeroGp ^ i;
    else oneGp = oneGp ^ i;
  }

  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(nums[i] == zeroGp) cnt++;
  }

  if(cnt == 2) return {zeroGp, oneGp}; // {repeating, missing}

  return {oneGp, zeroGp};
}

int main() {
  vector<int> nums = {3, 5, 4, 1, 1};

  // vector<int> ans = solutionBrute(nums);

  // vector<int> ans = solutionBetter(nums);

  // vector<int> ans = solutionOptimal_1(nums);

  vector<int> ans = solutionOptimal_2(nums);
  for(auto i : ans) {
    cout << i << " ";
  } cout << endl;
}