// Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
// A subarray is a contiguous non-empty sequence of elements within an array.

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T = O(n^3)
// S = O(1)
int largestSum(vector<int>& arr) {
  int n = arr.size();
  int sum = 0;
  int start, end;

  for(int i = 0; i < n; i++) {
    start = i;

    for(int j = i; j < n; j++) {
      end = j;

      int checkSum = 0;
      for(int k = start; k <= end; k++) {
        checkSum += arr[k];
      }
      
      if(sum < checkSum) {
        sum = 0;
        sum = checkSum;
      }

    }
  }

  return sum;
}

int main() {
  vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};


  cout << largestSum(arr) << endl;
  cout << "completed\n";
}