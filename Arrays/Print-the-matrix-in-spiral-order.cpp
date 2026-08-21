// Given a Matrix, print the given matrix in spiral order.

#include <bits/stdc++.h>
using namespace std;

// T = O(n * m)
// S = O(n * m)
vector<int> spiralMatrix(vector<vector<int>>& mat) {
  int n = mat.size();
  int m = mat[0].size();

  int top = 0;
  int bottom = n-1;

  int left = 0;
  int right = m-1;
  vector<int> ans;

  // suppose we have only one line
  // * * * * * * * *
  // then when after first top++, top > bottom

  while(top <= bottom && left <= right) {
    for(int i = left; i <= right; i++) { // loop condition checks if there are any elements by i (left) <= right
      ans.push_back(mat[top][i]);
    } top++;
    
    for(int i = top; i <= bottom; i++) { // loop condition checks if top < bottom
      ans.push_back(mat[i][right]);
    } right--;
    
    // Above loops do not need any extra conditions because left and right change after the above loops, and after changing top we are checking if top < bottom in second loop above.

    if(top <= bottom) {
      for(int i = right; i >= left; i--) { // this loop checks left < right but doesn't check if top has already exceeded bottom so we apply the condition
        ans.push_back(mat[bottom][i]);
      } bottom--;
    }
  
    if(left <= bottom) {
      for(int i = bottom; i >= top; i--) { // this loop checks top < bottom but it does not check the case when there are no more elements so that we do have a top! Means we need to check if there are elements present after top > bottom (which ofc is always false if top > bottom)
        ans.push_back(mat[i][left]);
      } left++;
    }
  }

  return ans;
}

int main() {
  vector<vector<int>> matrix = {
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12}
    };

  vector<int> ans = spiralMatrix(matrix);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}