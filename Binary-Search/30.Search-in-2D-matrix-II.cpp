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

  cout << searchMatrix(matrix, target) << endl;
}