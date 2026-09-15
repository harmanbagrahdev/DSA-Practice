// You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n)
// S = O(1)
int squareRoot(int n) {
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(i*i <= n) ans = max(ans, i);
  }

  return ans;
}

// Optimal solution
// T = O(log(n))
// S = O(1)
int squareRootOptimal(int n) {
  int ans = 0;
  int low = 1, high = n;

  while(low <= high) {
    int mid = (low + high) / 2;

    if(mid * mid <= n) {
      ans = mid;
      low = mid+1;
    }

    else high = mid-1;
  }

  return ans;
}

int main() {
  int n = 36;

  // cout << squareRoot(n) << endl;

  cout << squareRootOptimal(n) << endl;
}