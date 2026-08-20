// Given a Matrix, print the given matrix in spiral order.

// complete it by tomorrow
#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& mat) {
  int n = mat.size();
  int m = mat[0].size();

  int top = 0;
  int bottom = n-1;

  int left = 0;
  int right = m-1;
  vector<int> ans;

  for(int i = left; i <= right; i++) {
    ans.push_back(mat[top][i]);
  } top++;

  for(int i = top; i <= bottom; i++) {
    ans.push_back(mat[i][right]);
  } right--;

  for(int i = right; i >= bottom; i--) {
    ans.push_back(mat[bottom][i]);
  } bottom--;

  for(int i = bottom; i >= top; i--) {
    ans.push_back(mat[i][bottom]);
  } right--;

  return ans;
}

int main() {
  vector<vector<int>> matrix = {
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12},
      {13,14,15,16}
    };

  vector<int> ans = spiralMatrix(matrix);
  for (auto row : ans)
  {
    for (auto value : row)
      cout << value << " ";
    cout << endl;
  }
  cout << endl;
}