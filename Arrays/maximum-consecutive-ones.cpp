#include <bits/stdc++.h>
using namespace std;

// optimal solution
// T = O(n)
// S = O(1)
int maximumConsecutiveOnes(vector<int>& arr, int n) {
  int max = 0;
  int count = 0;

  for(int i = 0; i < n; i++) {
    if(arr[i] == 1) {
      count++;

      if(count > max) max = count;
    }

    if(arr[i] == 0) {
      count = 0;
    }
  }

  return max;
}

int main() {
  vector<int> arr = {0,1,0,1,1,1,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,0}; // max 1's = 8
  int n = arr.size();

  cout << maximumConsecutiveOnes(arr, n) << endl;
}