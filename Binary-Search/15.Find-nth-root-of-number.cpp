// You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n)
// S = O(1)
int nthRoot(int m, int n) {
  int ans = 0;
  for(int i = 1; i <= m; i++) {
    if(pow(i, n) <= m) ans = max(ans, i);
  }

  return ans;
}

// Optimal solution
// T = O(log(n))
// S = O(1)
int nthRootOptimal(int m, int n) {
  int low = 1, high = m;
  
  while(low <= high) {
    int ans = 1;
    int mid = (low + high) / 2;

    for(int i = 1; i <= n; i++) {
      ans *= mid;

      if(ans > m) break;
    }

    if(ans == m) return mid;
    else if(ans < m) low = mid+1; 
    else high = mid-1;
  }

  return -1;
}

int main() {
  int m = 27;
  int n = 3;

  // cout << nthRoot(m, n) << endl;

  cout << nthRootOptimal(m, n) << endl;
}