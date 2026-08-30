// Given two sorted integer arrays nums1 and nums2, merge both the arrays into a single array sorted in non-decreasing order.
// The final sorted array should be stored inside the array nums1 and it should be done in-place.
// Array nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s whereas nums2 has a length of n.

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T = O(n1 + n2) + O(n1 + n2)
// S = O(n1 + n2)
vector<int> mergeArrays(vector<int>& nums1, vector<int>& nums2) {
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

  return nums1;
}

vector<int> mergeArraysOptimal_1(vector<int>& nums1, vector<int>& nums2) {
  int n1 = nums1.size();
  int n2 = nums2.size();

  int left = 0;
  int right = 0;
  
  while(left <= 0 && right < n2) {
    if(nums1[left] > nums2[right]) {
      swap(nums1[left], nums2[right]);
      left++;
      right--;
    }

    else break;
  }

  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
}

int main() {
  vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0};
  vector<int> nums2 = {-3, 1, 8};

  vector<int> ans = mergeArraysOptimal_1(nums1, nums2);

  for(auto i : ans) {
    cout << i << " ";
  } cout << endl;

  // vector<int> ans = mergeArrays(nums1, nums2);

  // for(auto i : ans) {
  //   cout << i << " ";
  // } cout << endl;

  // for(auto i : nums2) {
  //   cout << i << " ";
  // } cout << endl;
}