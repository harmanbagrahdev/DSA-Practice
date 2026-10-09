#include <bits/stdc++.h>
using namespace std;

// Brute
// T = O(n)
// S = O(1)
class BruteForceSolution
{
public:
  int countGoodNumbers(long long n)
  {
    long long MOD = 1e9 + 7;
    long long ans = 1;

    // Loop through each index from 0 to n-1
    for (long long i = 0; i < n; ++i)
    {
      if (i % 2 == 0)
      {
        ans = (ans * 5) % MOD; // Even index: 5 choices (0, 2, 4, 6, 8)
      }
      else
      {
        ans = (ans * 4) % MOD; // Odd index: 4 choices (2, 3, 5, 7)
      }
    }

    return ans;
  }
};

// Optimal
// T = O(log(n))
// S = O(1)
class OptimalSolution
{
public:
  const int MOD = 1e9 + 7;

  // Fast modular exponentiation: O(log exp)
  long long power(long long base, long long exp)
  {
    long long res = 1;
    base = base % MOD;

    while (exp > 0)
    {
      if (exp % 2 == 1)
      { // If exponent is odd
        res = (res * base) % MOD;
      }
      base = (base * base) % MOD; // Square the base
      exp /= 2;                   // Divide exponent by 2
    }
    return res;
  }

  int countGoodNumbers(long long n)
  {
    long long evenPositions = (n + 1) / 2;
    long long oddPositions = n / 2;

    long long evenChoices = power(5, evenPositions);
    long long oddChoices = power(4, oddPositions);

    return (evenChoices * oddChoices) % MOD;
  }
};

int main()
{
  long long n;
  cout << "Enter the length of the digit string (n): ";
  if (!(cin >> n))
    return 0;

  // 1. Run Optimal Solution
  OptimalSolution os;
  int optimalAns = os.countGoodNumbers(n);
  cout << "Optimal Solution Result: " << optimalAns << "\n";

  // 2. Run Brute Force Solution safely
  // Guarding against large n values to prevent terminal hanging / crash states
  if (n <= 10000000)
  {
    BruteForceSolution bfs;
    int bruteAns = bfs.countGoodNumbers(n);
    cout << "Brute Force Result:     " << bruteAns << "\n";
  }
  else
  {
    cout << "Brute Force skipped to avoid Time Limit Exceeded (n > 10^7)\n";
  }
}