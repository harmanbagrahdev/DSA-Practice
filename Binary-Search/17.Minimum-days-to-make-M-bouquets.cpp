// You are given 'N’ roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
// You can only pick already bloomed roses that are adjacent to make a bouquet.
// You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
// Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

#include <bits/stdc++.h>
using namespace std;

// int bouquets(vector<int>& days, int m, int k) {
//   int min = *min_element(days.begin(), days.end());
//   int max = *max_element(days.begin(), days.end());
//   int bouquets = 0;

//   for(int i = min; i <= max; i++) {
//     int cnt = 0;
//     for(int j = 0; j < days.size(); j++) {
//       if(days[j] <= i) cnt++;
//       else if(cnt >= k) bouquets++;
//       else cnt = 0;
//     }

//     if(bouquets == m) break;
//     return i;
//   }

//   return -1;
// }

class Solution
{
public:
  bool isPossible(vector<int> &bloomDays, int day, int m, int k)
  {
    int count = 0;
    int bouquets = 0;

    for (int bloom : bloomDays)
    {
      if (bloom <= day)
      {
        count++;
        if (count == k)
        {
          bouquets++;
          count = 0;
        }
      }
      else
      {
        count = 0;
      }
    }

    return bouquets >= m;
  }

  int minDays(vector<int> &bloomDays, int m, int k)
  {
    long long totalFlowers = 1LL * m * k;
    if (totalFlowers > bloomDays.size())
      return -1;

    int low = *min_element(bloomDays.begin(), bloomDays.end());
    int high = *max_element(bloomDays.begin(), bloomDays.end());

    for (int day = low; day <= high; ++day)
    {
      if (isPossible(bloomDays, day, m, k))
      {
        return day;
      }
    }

    return -1;
  }
};

int main()
{
  vector<int> days = {7, 7, 7, 7, 13, 11, 12, 7};
  int m = 2;
  int k = 3;

  // cout << bouquets(days, m, k) << endl;
}