// A monkey Koko is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

#include <bits/stdc++.h>
using namespace std;

// T = O( max(arr[i]) )
int calculatetotalhrs(vector<int>& arr, int hourly) {
  int totalhrs = 0;
  for (auto pile : arr) {
    totalhrs += ceil( (double)pile / (double)hourly);
  }
  
  return totalhrs;
}

// Brute Force
// T = O(n * max(arr[i]) )
// S = O(1)
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

// Optimal solution
// T = O(n) * O( log(max(arr[i])) )
// S = O(1)
int minEatingSpeedOptimal(vector<int>& arr, int h) {
  int low = 1;
  int high = *max_element(arr.begin(), arr.end()); // O(n)

  while(low <= high) {
    int mid = (low + high) / 2;
    int hours = calculatetotalhrs(arr, mid);

    if(hours == h) return mid;
    else if(hours < h) high = mid-1;
    else low = mid+1;
  }

  return low;
}

int main() {
  vector<int> arr = {312884470};
  int h = 312884469;

  // cout << minEatingSpeed(arr, h) << endl;

  cout << minEatingSpeedOptimal(arr, h) << endl;
}