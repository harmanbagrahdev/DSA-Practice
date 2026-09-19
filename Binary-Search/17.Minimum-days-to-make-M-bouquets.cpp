// You are given 'N’ roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
// You can only pick already bloomed roses that are adjacent to make a bouquet.
// You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
// Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

#include <bits/stdc++.h>
using namespace std;

// Brute : My Solution
// T = O(n) * O(max - min + 1)
// S = O(1)
int bouquets(vector<int>& days, int m, int k) {
  long long totalFlowers = 1LL * m * 1LL * k;
  if (totalFlowers > days.size())
    return -1;

  int min = *min_element(days.begin(), days.end());
  int max = *max_element(days.begin(), days.end());
  
  for(int i = min; i <= max; i++) {
    int cnt = 0;
    int bouquets = 0;
    for(auto day : days) {
      if(day <= i) {
        cnt++;
        if(cnt == k) {
          bouquets++;
          cnt = 0;
        }
      }
      else cnt = 0;

      if(bouquets >= m) return i;
    }
  }

  return -1;
}

class Solution
{
public:
  bool isPossible(vector<int> &days, int day, int m, int k)
  {
    int count = 0;
    int bouquets = 0;

    for (int bloom : days)
    {
      if (bloom <= day)
      {
        count++;
        if (count == k)
        {
          bouquets++;
          count = 0;

          if(bouquets >= m) return 1;
        }
      }
      else
      {
        count = 0;
      }
    }

    return 0;
  }

  // Brute Force
  // T = O(n) * O(max - min + 1)
  // S = O(1)
  int minDays(vector<int> &days, int m, int k)
  {
    long long totalFlowers = 1LL * m * 1LL * k;
    if (totalFlowers > days.size())
      return -1;

    int low = *min_element(days.begin(), days.end());
    int high = *max_element(days.begin(), days.end());

    for (int day = low; day <= high; ++day)
    {
      if (isPossible(days, day, m, k))
      {
        return day;
      }
    }

    return -1;
  }

  // Optimal
  // T = O(n) * O( log(max - min + 1) )
  // S = O(1)
  int minDaysOptimal(vector<int>& days, int m, int k) {
    long long totalFlowers = 1LL * m * 1LL * k;
    if(totalFlowers > days.size()) return -1;

    int low = *min_element(days.begin(), days.end()); // O(n)
    int high = *max_element(days.begin(), days.end()); // O(n)
    // int ans = -1;

    while(low <= high) {
      long long mid = low + (high - low) / 2;

      if(isPossible(days, mid, m, k)) {
        // ans = mid;
        high = mid-1;
      }

      else if(!isPossible(days, mid, m, k)) low = mid+1;
    }

    return low;
  }
};

int main()
{
  vector<int> days = {7, 7, 7, 7, 13, 11, 12, 7};
  int m = 2;
  int k = 3;

  // cout << bouquets(days, m, k) << endl;

  Solution s;
  // cout << s.minDays(days, m, k) << endl;
  cout << s.minDaysOptimal(days, m, k) << endl;
}