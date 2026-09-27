// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

#include <bits/stdc++.h>
using namespace std;
// Brute force
// T = O(n) + O(n1 + n2)
// S = O(1)
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
  int m = nums1.size();
  int n = nums2.size();

  int i = 0;
  while (i < n)
  {
    nums1.push_back(nums2[i++]);
  }

  sort(nums1.begin(), nums1.end()); // O(n1 + n2)

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

// Optimal solution
// T = O(log(min(n1, n2)))
// S = O(1)
double findMedianSortedArraysOptimal(vector<int> &nums1, vector<int> &nums2) {
  if(nums2.size() < nums1.size()) return findMedianSortedArraysOptimal(nums2, nums1); // do bs on smaller array! -- to reduce the search space

  int n1 = nums1.size();
  int n2 = nums2.size();
  int low = 0, high = n1;

  while(low <= high) {
    int p1 = (low + high) / 2; // partition in first array
    int p2 = (n1 + n2 + 1) / 2 - p1; // partition in second array

    int left1 = p1 == 0 ? INT_MIN : nums1[p1 - 1];
    int left2 = p2 == 0 ? INT_MIN : nums2[p2 - 1];

    int right1 = p1 == n1 ? INT_MAX : nums1[p1];
    int right2 = p2 == n2 ? INT_MAX : nums2[p2];

    if(left1 <= right2 && left2 <= right1) { // to check if valid
      if((n1 + n2) % 2 == 0) { // for even length
        return ( max(left1, left2) + min(right1, right2) ) / 2.0;
      }
      else return max(left1, left2); // for odd length
    }

    else if(left1 > right2) high = p1-1;
    else low = p1+1;
  }

  return 0.0;
}

int main()
{
  vector<int> nums1 = {1,3}, nums2 = {2};

  // cout << findMedianSortedArrays(nums1, nums2) << endl;

  cout << findMedianSortedArraysOptimal(nums1, nums2) << endl;
}