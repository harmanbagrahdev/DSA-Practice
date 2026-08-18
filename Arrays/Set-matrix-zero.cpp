// Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix

#include <bits/stdc++.h>
using namespace std;

// // My solution : Brute (fails in case of multiple zeroes)
// // T = O(n^2)
// // S = O(1) --> auxilliary space
// vector<vector<int>> setZero(vector<vector<int>>& matrix) {
//   int row = -1, column = -1;

//   for(int i = 0; i < matrix.size(); i++) {
//     for(int j = 0; j < matrix[0].size(); j++) {
//       if(matrix[i][j] == 0) {
//         row = i;
//         column = j;
//       }
//       // matrix[row][j] = 0;
//       // matrix[i][column] = 0;
//     }
//   }

//   for(int i = 0; i < matrix.size(); i++) {
//     matrix[i][column] = 0;
    
//     for(int j = 0; j < matrix[0].size(); j++) {
//       matrix[row][j] = 0;
//     }
//   }

//   return matrix;
// }

// vector<int> markRow(vector<int>& matrix, int& col, int& row) {
//   for(int i = 0; i < matrix.size(); i++) {
//     matrix[i][col] = 0;
    
//     for(int j = 0; j < matrix[0].size(); j++) {
//       matrix[row][j] = 0;
//     }
//   }
// }

// // Brute Force
// // T = O()
// // S = O()
// vector<vector<int>> setZero(vector<vector<int>>& matrix, int row, int col) {
//   for(int i = 0; i < row; i++) {
//     for(int j = 0; j < col; j++) {
//       if(matrix[i][j] == 0) {
//         markRow(i);
//         markcolumn(j);
//       }
//     }
//   }
  
//   return matrix;
// }


vector<vector<int>> setZero(vector<vector<int>>& matrix, int row, int col) {
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


int main() {
  vector<vector<int>> matrix = {
    {0,1,0},
    {1,1,1},
    {1,1,1}
  };

  int row = matrix.size();
  int col = matrix[0].size();

  vector<vector<int>> ans = setZero(matrix, row, col);
  for(auto row : ans) {
    for(auto value : row) {
      cout << value << " ";
    }
    cout << endl;
  }
}