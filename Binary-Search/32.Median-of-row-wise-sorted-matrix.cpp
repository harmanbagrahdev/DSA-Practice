// Given a row-wise sorted matrix mat, find the median of all elements in the matrix.Each row is sorted in non-decreasing order.
// The total number of elements is odd, so the median is the exact middle element after all matrix values are arranged in sorted order.

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n*m + n) 
// S = (m * n)
int medianOfMatrix(vector<vector<int>>& matrix) {
  vector<int> arr;

  for(auto row : matrix) { // O(n*m)
    for(int el : row) {
      arr.push_back(el);
    }
  }

  sort(arr.begin(), arr.end()); // O((n*m) * log(n*m))

  return arr[(arr.size() / 2)]; // O(1)
}

// Optimal Solution
// T = O(r + r × log(c) × log(ValueRange)) --> ValueRange is the range between the smallest and largest values in the matrix !
// S = O(1)
int upperBound(vector<int>& arr, int c, int x) {
  int low = 0;
  int high = c-1;

  while(low <= high) {
    int mid = low + (high - low) / 2;

    if(arr[mid] > x) high = mid-1;
    else low = mid+1;
  }

  return low;
}

int cntSmallEqual(vector<vector<int>>& matrix, int r, int c, int mid) {
  int cnt = 0;

  for(int i = 0; i < r; i++) {
    cnt += upperBound(matrix[i], c, mid);
  }

  return cnt;
}

int medianOfMatrixOptimal(vector<vector<int>>& matrix) {
  int low = INT_MAX, high = INT_MIN;
  int r = matrix.size();
  int c = matrix[0].size();

  for(int i = 0; i < r; i++) {
    low = min(low, matrix[i][0]);
    high = max(high, matrix[i][c-1]);
  }

  int req = (r * c) / 2;
  while(low <= high) {
    int mid = low + (high - low) / 2;
    int smallEqual = cntSmallEqual(matrix, r, c, mid);

    if(smallEqual <= req) low = mid+1;
    else high = mid-1;
  }

  return low;
}

int main() {
  vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  // cout << medianOfMatrix(matrix) << endl;
  
  cout << medianOfMatrixOptimal(matrix) << endl;
}