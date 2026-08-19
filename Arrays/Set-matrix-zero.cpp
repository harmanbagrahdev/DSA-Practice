// Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix

#include <bits/stdc++.h>
using namespace std;

// My solution : Brute (fails in case of multiple zeroes)
// T = O(row * col)
// S = O(1) --> auxilliary space
vector<vector<int>> setZeroBuggy(vector<vector<int>>& matrix) {
  int row = -1, column = -1;

  for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[0].size(); j++) {
      if(matrix[i][j] == 0) {
        row = i;
        column = j;
      }
    }
  }

  for(int i = 0; i < matrix.size(); i++) {
    matrix[i][column] = 0;
    
    for(int j = 0; j < matrix[0].size(); j++) {
      matrix[row][j] = 0;
    }
  }

  return matrix;
}

void markRow(vector<vector<int>>& matrix, int& row) {
  for(int j = 0; j < matrix.size(); j++) {
    if(matrix[row][j] != 0) matrix[row][j] = -1;
  }
}

void markColumn (vector<vector<int>>& matrix, int col) {
  for(int j = 0; j < matrix[0].size(); j++) {
    if(matrix[j][col] != 0) matrix[j][col] = -1;
  }
}

// Brute Force
// T = O(nearly n^3)
// S = O(1)
vector<vector<int>> setZeroBrute(vector<vector<int>>& matrix, int row, int col) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(matrix[i][j] == 0) {
        markRow(matrix, i);
        markColumn(matrix, j);
      }
    }
  }

  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(matrix[i][j] == -1) matrix[i][j] = 0;
    }
  }
  
  return matrix;
}

// Better solution
// T = O( 2* (row * col) )
// S = O(col + row)
vector<vector<int>> setZeroBetter(vector<vector<int>>& matrix, int row, int col) {
  vector<int> colCnt(col, 0), rowCnt(row, 0);

  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(matrix[i][j] == 0) {
        rowCnt[i] = 1;
        colCnt[j] = 1;
      }
    }
  }

  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(rowCnt[i] == 1 || colCnt[j] == 1) matrix[i][j] = 0;
    }
  }

  return matrix;
}

// Optimal Solution
// T = O(row * col)
// S = O(1)
vector<vector<int>> setZeroOptimal(vector<vector<int>>& matrix, int row, int col) {
  // vector<int> colCnt(col, 0), rowCnt(row, 0);  -->  (for reference)

  int col0 = 1; // separate var due to collision

  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(matrix[i][j] == 0) {
        matrix[i][0] = 0; // mark first row

        if(j != 0) matrix[0][j] = 0; // mark first column
        else col0 = 0;
      }
    }
  }

  for(int i = 1; i < row; i++) {
    for(int j = 1; j < col; j++) {
      if(matrix[i][j] != 0) {
        if(matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
  }

  if(matrix[0][0] == 0) {
    for(int j = 1; j < col; j++) matrix[0][j] = 0;
  }

  if(col0 == 0) {
    for(int j = 0; j < row; j++) matrix[j][0] = 0;
  }

  return matrix;
}


int main() {
  vector<vector<int>> matrix = {
    {1,1,1},
    {1,1,0},
    {0,1,1}
  };

  int row = matrix.size();
  int col = matrix[0].size();

  // vector<vector<int>> ans = setZeroBrute(matrix, row, col);

  // vector<vector<int>> ans = setZeroBetter(matrix, row, col);

  vector<vector<int>> ans = setZeroOptimal(matrix, row, col);
  for(auto row : ans) {
    for(auto value : row) {
      cout << value << " ";
    }
    cout << endl;
  }
}