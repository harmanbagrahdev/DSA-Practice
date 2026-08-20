// Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise. The rotation must be done in place, meaning the input 2D matrix must be modified directly

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T = O(n^2)
// S = (n^2)
vector<vector<int>> rotateImageBrute(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> rotated(m, vector<int>(n));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      rotated[j][n-1-i] = matrix[i][j]; // transpose matrix but change the column number
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      matrix[i][j] = rotated[i][j];
    }
  }

  return rotated;
}

// Optimal solution
// T = O(n^2 + n * n/2) = O(n^2)
// S = O(1)
vector<vector<int>> rotateImageOptimal(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  
  // now for one trace only
  for (int i = 0; i < n-1; i++)
  {
    for (int j = i+1; j < m; j++)
    {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  
  for(int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end()); // T = O(n / 2) --> logically running for half part of matrix (trace)
  }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     if(i < j) swap(matrix[i][j], matrix[j][i]);
  //   }
  // }
  
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     if(j <= (m-1) / 2) swap(matrix[i][j], matrix[i][m-1-j]);
  //   }
  // }

  return matrix;
}

int main()
{
  vector<vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
    };

  // vector<vector<int>> ans = rotateImageBrute(matrix);

  vector<vector<int>> ans = rotateImageOptimal(matrix);
  for (auto row : ans)
  {
    for (auto value : row)
      cout << value << " ";
    cout << endl;
  }
  cout << endl;
}