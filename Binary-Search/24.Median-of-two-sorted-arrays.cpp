// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
  int m = nums1.size();
  int n = nums2.size();

  int i = 0;
  while (i < n)
  {
    nums1.push_back(nums2[i++]);
  }

  sort(nums1.begin(), nums1.end());

  int mid = nums1.size() / 2;
  double ans = 0;
  if (nums1.size() % 2 == 0)
  {
    ans = (nums1[mid - 1] + nums1[mid]) / 2.0;
  }
  else
    ans = nums1[mid];

  return ans;
}

int main()
{
  vector<int> nums1 = {1,3}, nums2 = {2};

  cout << findMedianSortedArrays(nums1, nums2) << endl;
}