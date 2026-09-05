// Given an array of numbers, you need to return the count of reverse pairs.
// Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j]

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T = O(n^2)
// S = O(1)
int cntReversePairsBrute(vector<int>& nums) {
  int n = nums.size();
  int cnt = 0;

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      if(nums[i] > (2LL * nums[j]) ) cnt++; // LL due to integer overflow
    }    
  }

  return cnt;
}

// Optimal Solution
// T = O(2n * log(n) )
// S = O(n) --> but array is changed
void merge(vector<int>& nums, int low, int mid, int high) {
  int n = nums.size();
  int left = low;
  int right = mid+1;
  vector<int> temp;
  int cnt = 0;

  while(left <= mid && right <= high) {
    if(nums[left] <= nums[right]) {
      temp.push_back(nums[left++]);
    }
    else temp.push_back(nums[right++]);

    while(left <= mid) temp.push_back(nums[left++]);
    while(right <= high) temp.push_back(nums[right++]);
  }

  for(int i = low; i <= high; i++) {
    nums[i] = temp[i - low];
  }
}

int cntPairs(vector<int>& nums, int low, int mid, int high) {
  int cnt = 0;
  int right = mid+1;

  // T = O(n)
  for(int i = low; i <= mid; i++) {
    while(right <= high && nums[i] > (2LL * nums[right])) right++;

    cnt += (right - (mid+1) );
  }

  return cnt;
}

int mergeSort(vector<int>& nums, int low, int high) {
  int cnt = 0;
  if(low >= high) return cnt;
  int mid = (low + high) / 2;

  cnt += mergeSort(nums, low, mid);
  cnt += mergeSort(nums, mid+1, high);
  cnt += cntPairs(nums, low, mid, high);
  merge(nums, low, mid, high);
  return cnt;
}

int cntReversePairsOptimal(vector<int>& nums) {
  return mergeSort(nums, 0, nums.size() - 1);
}

int main() {
  vector<int> nums = {1,3,2,3,1};

  // cout << cntReversePairsBrute(nums) << endl;

  cout << cntReversePairsOptimal(nums) << endl;
}