// Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.

// If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.

#include <bits/stdc++.h>
using namespace std;

int rowWithMaxOnes(vector<vector<int>>& matrix, int m, int n) {
  int maxCnt = -1;
  int maxRowIndex = -1;
  for(int i = 0; i < m; i++) {
    int cnt = 0;
    for(int j = 0; j < n; j++) {
      if(matrix[i][j] == 1) cnt++;
    }

    if(cnt > maxCnt) {
      maxCnt = cnt;
      maxRowIndex = i;
    }
  }

  return maxRowIndex;
}

int main() {
  int m = 3;
  int n = 3;
  vector<vector<int>> matrix(m, vector<int>(n));
  matrix = {
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 0} 
  };
  
  cout << rowWithMaxOnes(matrix, m, n) << endl;
}