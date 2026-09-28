// You are given a sorted array representing the exact integer positions of several gas stations on a highway.
// You are also given an integer k, which represents the number of brand new gas stations you are allowed to build.
// You can place these new gas stations anywhere on the highway, including at non-integer decimal positions.
// Your objective is to place these k new stations in a way that minimizes the maximum distance between any two adjacent gas stations.
// You must return this optimized maximum distance, accurate to 1e-6.

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(k * n)
// S = O(n)
long double minimizeMaxDistance(vector<int> &arr, int k)
{
  int n = arr.size();
  // Array to track how many new stations are added in each original gap
  vector<int> howMany(n - 1, 0);

  // Place k stations one by one in the largest available gaps
  for (int stations = 1; stations <= k; stations++)
  {
    long double maxSection = -1.0;
    int maxIndex = -1;

    // Scan all gaps to find the current maximum section length
    for (int i = 0; i < n - 1; i++)
    {
      long double diff = arr[i + 1] - arr[i];
      long double sectionLength = diff / (long double)(howMany[i] + 1);

      // Keep track of the largest gap found
      if (sectionLength > maxSection)
      {
        maxSection = sectionLength;
        maxIndex = i;
      }
    }

    // Add one station to the largest found gap
    howMany[maxIndex]++;
  }

  long double maxAns = -1.0;

  // Calculate the final maximum distance across all sections
  for (int i = 0; i < n - 1; i++)
  {
    long double diff = arr[i + 1] - arr[i];
    long double sectionLength = diff / (long double)(howMany[i] + 1);
    maxAns = max(maxAns, sectionLength);
  }

  return maxAns;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 4;

  cout << minimizeMaxDistance(arr, k) << endl;
}