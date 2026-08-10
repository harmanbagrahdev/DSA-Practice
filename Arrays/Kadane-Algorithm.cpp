// Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
// A subarray is a contiguous non-empty sequence of elements within an array.

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T = O(n^3)
// S = O(1)
int largestSum(vector<int>& arr) {
  int n = arr.size();
  int maxi = INT16_MIN;
  int start, end;

  for(int i = 0; i < n; i++) {
    start = i;

    for(int j = i; j < n; j++) {
      end = j;

      int sum = 0;
      for(int k = start; k <= end; k++) {
        sum += arr[k];
        maxi = max(maxi, sum);
      }
    }
  }

  return maxi;
}

// Better solution
// T = O(n^2)
// S = O(1)
int largestSumBetter(vector<int>& arr) {
  int n = arr.size();
  int maxi = INT16_MIN;
  int start, end;

  for(int i = 0; i < n; i++) {
    start = i;
    int sum = 0;

    for(int j = i; j < n; j++) {
      sum += arr[j];
      maxi = max(maxi, sum);
    }
  }

  return maxi;
}

// Optimal solution
// T = O(n)
// S = O(1)
int largestSumOptimal(vector<int>& arr) {
  int n = arr.size();
  int maxi = INT16_MIN;
  int sum = 0;

  int start = 0, end = 0;
  int ansStart, ansEnd;

  for(int i = 0; i < n; i++) {
    if(sum == 0) start = i; // if we need to print the subarray

    sum += arr[i];
    if(sum > maxi) {
      ansStart = start, ansEnd = i; // if we need to print the subarray
    }
    
    maxi = max(maxi, sum);

    if(sum < 0) sum = 0;
  }

  if(sum < 0) maxi = 0; // incase there is no subarray with sum > 0 then return 0

  // incase there is no subarray with sum > 0 then return 0
  for(int i = ansStart; i <= ansEnd; i++) {
    cout << arr[i] << " ";
  } cout << endl;

  return maxi;
}

int main() {
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};


  // cout << largestSum(arr) << endl;

  // cout << largestSumBetter(arr) << endl;

  cout << largestSumOptimal(arr) << endl;

  cout << "completed\n";
}