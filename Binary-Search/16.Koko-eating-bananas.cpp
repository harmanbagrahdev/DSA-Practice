// A monkey Koko is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n * max(arr[i]) )
// S = O(1)
int calculatetotalhrs(vector<int>& arr, int hourly) {
  int totalhrs = 0;
  for (int pile : arr) {
    totalhrs += (pile + hourly - 1) / hourly;
  }

  return totalhrs;
}

int minEatingSpeed(vector<int>& arr, int h) {
  int maxVal = *max_element(arr.begin(), arr.end());

  for (int i = 1; i <= maxVal; i++) {
    int hours = calculatetotalhrs(arr, i);

    if (hours <= h) {
      return i;
    }
  }

  return maxVal;
}

int main() {
  vector<int> arr = {7, 15, 6, 3};
  int h = 8;

  cout << minEatingSpeed(arr, h) << endl;
}