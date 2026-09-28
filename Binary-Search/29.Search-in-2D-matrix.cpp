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

  cout << searchMatrix(matrix, target) << endl;
}