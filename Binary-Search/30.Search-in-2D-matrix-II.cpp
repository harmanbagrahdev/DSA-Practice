// Given a 2D array matrix where each row is sorted in ascending order from left to right and each column is sorted in ascending order from top to bottom.
// write an efficient algorithm to search for a specific integer target in the matrix.

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  for (auto &row : matrix)
  {
    for (int el : row)
    {
      if (el == target)
        return true;
    }
  }

  return false;
}

// T = O(log(m))
int lowerBound(vector<int>& arr, int x) {
  int low = 0, high = arr.size()-1;
  int ans = arr.size();
  while(low <= high) {
    int mid = (low + high) / 2;

    if(arr[mid] >= x) {
      ans = mid;
      high = mid-1;
    }

    else low = mid+1;
  }

  return ans;
}

// Better Solution
// T = O(n * log(m))
// S = O(1)
vector<int> searchMatrixBetter(vector<vector<int>>& matrix, int target) {
  int m = matrix.size();
  for(int i = 0; i < m; i++) {
    int rowIndex = lowerBound(matrix[i], target);

    if(rowIndex != -1 && matrix[i][rowIndex] == target) {
      return {i, rowIndex};
    }
  }

  return {-1, -1};
}

// Optimal solution
// T = O(n + m)
// S = O(1)
pair<int, int> searchMatrixOptimal(vector<vector<int>>& matrix, int target) {
  if(matrix.empty() || matrix[0].empty()) return {-1, -1};

  int row = matrix.size();
  int col = matrix[0].size();

  int r = 0;
  int c = col - 1;
  while(r < row && c >= 0) {
    if(target == matrix[r][c]) return {r, c};
    else if(target < matrix[r][c]) c --;
    else r ++;
  }

  return {-1, -1};
}

int main()
{
  int m = 5;
  int n = 5;
  vector<vector<int>> matrix(m, vector<int>(n));
  matrix = {
    {1,4,7,11,15},
    {2,5,8,12,19},
    {3,6,9,16,22},
    {10,13,14,17,24},
    {18,21,23,26,30}
  };
  int target = 5;

  // cout << searchMatrix(matrix, target) << endl;

  // vector<int> ans = searchMatrixBetter(matrix, target);
  // for(auto i : ans) {
  //   cout << i << " ";
  // }
  // cout << endl;

  auto [row, col] = searchMatrixOptimal(matrix, target);
  cout << row << " " << col << endl;
}