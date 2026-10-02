// Given a 0-indexed M x N matrix matrix, find any peak element and return its position as {row, col}.
// A cell is called a peak if it is strictly greater than its adjacent neighbors on the left, right, top, and bottom.
// The matrix is surrounded by a border of -1, and no two adjacent cells are equal.
// In simple words, find any cell that is bigger than every valid up, down, left, and right neighbor.

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T = O(m * n)
// S = O(1)
pair<int, int> peakElement(vector<vector<int>> &matrix)
{
  if (matrix.empty())
    return {-1, -1};

  int el = INT_MIN;

  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      if (matrix[i][j] > el)
      {
        el = matrix[i][j];
        return {i, j};
      }
    }
  }

  return {-1, -1};
}

int findRowIndex(vector<vector<int>>& matrix, int r, int mid) {
  int maxValue = -1;
  int maxIndex = -1;
  for(int i = 0; i < r; i++) {
    if(matrix[i][mid] > maxValue) {
      maxValue = matrix[i][mid];
      maxIndex = i;
    }
  }

  return maxIndex;
}

pair<int, int> peakElementOptimal(vector<vector<int>>& matrix) {
  if(matrix.empty()) return {-1, -1};

  int r = matrix.size();
  int c = matrix[0].size();

  int low = 0, high = c-1;

  while(low <= high) {
    int mid = (low + high) / 2;

    int maxRowIndex = findRowIndex(matrix, r, mid);
    int left = mid-1 >= 0 ? matrix[maxRowIndex][mid-1] : -1;
    int right = mid+1 <= c-1 ? matrix[maxRowIndex][mid+1] : -1;

    if(matrix[maxRowIndex][mid] > left && matrix[maxRowIndex][mid] > right) return {maxRowIndex, mid};
    else if(matrix[maxRowIndex][mid] < left) high = mid-1;
    else low = mid+1;
  }

  return {-1, -1};
}

int main()
{
  vector<vector<int>> matrix = {
      {40, 20, 15},
      {21, 30, 14},
      {7, 16, 32}
    };

  // auto [row, col] = peakElement(matrix);

  auto [row, col] = peakElementOptimal(matrix);
  cout << row << " " << col << endl;
}