// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

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

// Better Solution
// T = O(n + m)
// S = O(1)
pair<int, int> searchMatrixBetter(vector<vector<int>>& matrix, int target) {
  if(matrix.empty() || matrix[0].empty()) return {-1, -1};

  int row = matrix.size();
  int col = matrix[0].size();

  int r = 0;
  int c = col - 1;
  while(r < row && c >= 0) {
    if(target == matrix[r][c]) return {r, c};
    else if(target < matrix[r][c]) c -= 1;
    else r += 1;
  }

  return {-1, -1};
}

// Optimal solution : We will do binary search on whole matrix without putting all elements into extra array (using imaginary indeces) !
// T = O(log(n * m))
// S = O(1)
pair<int, int> searchMatrixOptimal(vector<vector<int>>& matrix, int target) {
  if(matrix.empty() || matrix[0].empty()) return {-1, -1};

  int row = matrix.size();
  int col = matrix[0].size();

  int low = 0;
  int high = (row * col) - 1;
  while(low <= high) {
    int mid = low + (high - low) / 2;
    int i = mid / col;
    int j = mid % col;

    if(target == matrix[i][j]) return {i, j};
    else if(target < matrix[i][j]) high = mid-1;
    else low = mid+1;
  }

  return {-1, -1};
}

int main()
{
  int m = 3;
  int n = 4;
  vector<vector<int>> matrix(m, vector<int>(n));
  matrix = {
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,60}
  };
  int target = 3;

  // cout << searchMatrix(matrix, target) << endl;

  // auto [row, col] = searchMatrixBetter(matrix, target);

  auto [row, col] = searchMatrixOptimal(matrix, target);
  cout << row << " " << col << endl;
}