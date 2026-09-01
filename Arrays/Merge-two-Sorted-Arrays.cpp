// Given two sorted integer arrays nums1 and nums2, merge both the arrays into a single array sorted in non-decreasing order.
// The final sorted array should be stored inside the array nums1 and it should be done in-place.
// Array nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s whereas nums2 has a length of n.

#include <bits/stdc++.h>
using namespace std;

// Brute force : we are sorting arrays but putting them again in nums1 and nums2
// T = O(n1 + n2) + O(n1 + n2)
// S = O(n1 + n2)
void mergeArraysBrute(vector<int>& nums1, vector<int>& nums2) {
  int n1 = nums1.size();
  int n2 = nums2.size();
  vector<int> temp;

  int i = 0;
  int j = 0;

  while(i < n1 && j < n2) {
    if(nums1[i] <= nums2[j]) temp.push_back(nums1[i++]);
    else if(nums1[i] > nums2[j]) temp.push_back(nums2[j++]);

  }

  while(i < n1) temp.push_back(nums1[i++]);
  while(j < n2) temp.push_back(nums2[j++]);


  for(int i = 0; i < (n1 + n2); i++) {
    if(i < n1) nums1[i] = temp[i];
    else nums2[i - n1] = temp[i];
  }
}

// Optimal Solution 1
// T = O( min(n1, n2) ) + O(n1 * loh(n1) ) + O(n2 * log(n2) )
// S = O(1)
void mergeArraysOptimal_1(vector<int>& nums1, vector<int>& nums2) {
  int n1 = nums1.size();
  int n2 = nums2.size();

  int left = n1-1;
  int right = 0;
  
  while(left >= 0 && right < n2) {
    if(nums1[left] > nums2[right]) {
      swap(nums1[left], nums2[right]);
      left--;
      right++;
    }
    else break;
  }

  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
}

// Optimal Solution 2 : By gap method
// T = O(log(n + m)) + O(n + m)
// S = O(1)
void swapGreater(vector<int>& nums1, vector<int>& nums2, int i, int j) {
  if(nums1[i] > nums2[j]) swap(nums1[i], nums2[j]);
}


void mergeArraysOptimal_2(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size();
  int m = nums2.size();

  int len = n + m;
  int gap = (len / 2) + (len % 2);
  
  while(gap > 0) {
    int left = 0;
    int right = left + gap;
    while(right < len) {
      // left in array 1 and right in array 2
      if(left < n && right >= n) {
        swapGreater(nums1, nums2, left, right - n);
      }
      // both in array 2
      else if(left >= n) {
        swapGreater(nums2, nums2, left - n, right - n);
      }
      // both in array 1
      else {
        swapGreater(nums1, nums1, left, right);
      }

      left++;
      right++;
    }

    if(gap == 1) break;
    gap = (gap / 2) + (gap % 2);
  }

}

// Leetcode problem solution
class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = m-1; // m is number of real elements in nums1
      int j = n-1; // n is the number of elements in nums2
      int k = m + n - 1; // last index of nums1 (writer pointer)
  
      while(j >= 0) {
        if(i >= 0 && nums1[i] > nums2[j]) {
          nums1[k--] = nums1[i--];
        }
        else {
          nums1[k--] = nums2[j--];
        }
      }
  }
};


int main() {
  vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0};
  vector<int> nums2 = {-3, 1, 8};

  // mergeArraysBrute(nums1, nums2);
  
  // mergeArraysOptimal_1(nums1, nums2);

  // mergeArraysOptimal_2(nums1, nums2);

  // for(auto i : nums1) {
  //   cout << i << " ";
  // } cout << endl;

  // for(auto i : nums2) {
  //   cout << i << " ";
  // } cout << endl;

  Solution s;
  s.merge(nums1, 4, nums2, 3);

  for(auto i : nums1) {
    cout << i << " ";
  } cout << endl;
}