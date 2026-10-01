// Given a 0-indexed M x N matrix matrix, find any peak element and return its position as {row, col}.
// A cell is called a peak if it is strictly greater than its adjacent neighbors on the left, right, top, and bottom.
// The matrix is surrounded by a border of -1, and no two adjacent cells are equal.
// In simple words, find any cell that is bigger than every valid up, down, left, and right neighbor.

#include <bits/stdc++.h>
using namespace std;

// Brute force : Buggyyyyyyyyy
// T = O(m * n)
// S = O(1)
pair<int, int> peakElement(vector<vector<int>>& matrix) {
  if(matrix.empty()) return {-1, -1};

  int r = matrix.size();
  int c = matrix[0].size();
  
  if(matrix[0][0] > matrix[0][1] && matrix[0][0] > matrix[1][0]) return {0, 0};
  else if(matrix[r-1][0] > matrix[r-1][1] && matrix[r-1][0] > matrix[(r-1) - 1][0]) return {r-1, 0};
  else if(matrix[0][c-1] > matrix[0][(c-1) -1] && matrix[0][c-1] > matrix[1][c-1]) return {c-1, 0};
  else if(matrix[r-1][c-1] > matrix[r-1][(c-1) -1] && matrix[r-1][c-1] > matrix[(r-1) - 1][c-1]) return {r-1, c-1};

  for(int i = 1; i < r-1; i++) {
    for(int j = 1; j < c-1; j++) {

      int current = matrix[i][j];
      if(current > matrix[i][j-1] && current > matrix[i][j+1] && current > matrix[i-1][j] && current > matrix[i+1][j]) {
        return {i, j};
      }
    }
  }

  return {-1, -1};
}

int main() {
  vector<vector<int>> matrix = {
    {40,20,15},
    {21,30,14},
    {7,16,32}
  };

  auto [row, col] = peakElement(matrix);
  cout << row << " " << col << endl;
}