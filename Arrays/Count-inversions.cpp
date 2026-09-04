#include <bits/stdc++.h>
using namespace std;

// Brute solution
// T = O(n^2)
// S = O(1)
int cntInversions(vector<int>& nums) {
  int n = nums.size();
  int cnt = 0;

  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      if(i < j && nums[i] > nums[j]) {
        cnt++;
      }
    }
  }
  return cnt;
}

// Optimal Solution
// T = O(n * log(n) )
// S = O(n) --> but we are changing the existing array so if we don't want to change the existing data then we could create a copy!
int merge(vector<int>& nums, int low, int mid, int high) {
  int left = low;
  int right = mid+1;
  vector<int> temp;

  int cnt = 0;
  while(left <= mid && right<= high) {
    if(nums[left] <= nums[right]) {
      temp.push_back(nums[left]);
      left++;
    }

    // when right is smaller add number of elements that can be our answer to the count var
    else {
      temp.push_back(nums[right]);
      cnt += (mid - left + 1);
      right++;
    }
  }

  while(left <= mid) {
    temp.push_back(nums[left++]);
  }

  while(right <= high) {
    temp.push_back(nums[right++]);
  }

  for(int i = low; i <= high; i++) {
    nums[i] = temp[i - low];
  }

  return cnt;
}

int mergeSort(vector<int>& nums, int low, int high) {
  int cnt = 0;
  if(low >= high) return cnt;
  int mid = (low + high) / 2;

  cnt += mergeSort(nums, low, mid);
  cnt += mergeSort(nums, mid+1, high);
  cnt += merge(nums, low, mid, high);

  return cnt;
}

int cntInversionsOptimal(vector<int>& nums) {
  return mergeSort(nums, 0, nums.size() - 1);
}

int main() {
  vector<int> nums = {5, 3, 2, 1, 4};

  // cout << cntInversions(nums) << endl;

  cout << cntInversionsOptimal(nums) << endl;
}
