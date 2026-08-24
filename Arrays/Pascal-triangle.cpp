// Write a program to generate Pascal's triangle. In Pascal’s triangle, each number is the sum of the two numbers directly above it.

#include <bits/stdc++.h>
using namespace std;

// Type 1: given R and C find element at that point. example : r = 3, n = 5 ( using nCr = n! / (r! * (n-r)! ) )
// In nCr (r <= n)
// We need r-1 and c-1 (formula) --->  (r-1) C (r-1)
// T = O(r)
// S = O(1)
int nCr(int n, int r) {
  long long result = 1;

  // Brute force is calculating Nr and Dr individually and then dividing them, needs more computation!
  // as (n-r)! will cancel out part of n! and there will be only r elements in Nr. after that.
  for(int i = 0; i < r; i++) {
    result *= (n - i);
    result /= (i + 1); // divide Nr. with r!'s elements in reverse order(Why?), so that they are always divisible with Nr.
  }

  return result;
}

// Type 2 : Print Nth row of pascal's triangle
// T = O(n * r)
// S = O(1)
// Brute approach
void printNthRowBrute(int n, int r, int N) {
  for(int i = 1; i <= n; i++) {
    cout << nCr(N, i-1) << " "; // T = O(r)
  }
  cout << endl;
}

// T = O(n)
// S = O(1)
// Optimal approach
void printNthRowOptimal(int N) {
  long long ans = 1;
  cout << ans << " ";
  for(int i = 1; i < N; i++) {
    ans = ans * (N - i);
    ans = ans / i;
    cout << ans << " ";
  }
  cout << endl;
} // There's some problem!


// Type 3 : Given n, print the entire pascal's triangle
void pascalTriangle(int n) {
  for(int i = 1; i <= n; i++) {
    printNthRowOptimal(i);
  }
}

int main() {
  int r = 3, n = 6;
  // cout << nCr(n - 1, r - 1) << endl;

  // printNthRowBrute(n - 1, r - 1, 3);

  // int N = 6;
  // printNthRowOptimal(N-1);

  pascalTriangle(6);
}