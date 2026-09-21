// A conveyor belt has packages that must be shipped from one port to another within days days.
// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
// We may not load more weight than the maximum weight capacity of the ship. 
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

#include <bits/stdc++.h>
using namespace std;

int daysNeeded(vector<int>& weights, int days) {
  int n = weights.size();
  long long totalDays = 0;
  for(auto i : weights) totalDays += i;
  int max = *max_element(weights.begin(), weights.end());

  int j = max;
  
  while(j <= totalDays) {
    int cnt = 1;
    long long sum = 0LL;

    for(int i = 0; i < n; i++) {
      if(sum + weights[i] > j){
        cnt++;
        sum = weights[i];
      }
      else if(sum <= j) sum += weights[i];
    }
    if(cnt <= days) return j;
    j++;
  }

  return -1;
}

int daysNeededOptimal(vector<int>& w, int c) {
  int days = 1;
  long long load = 0;

  for(auto x : w) {
    if(load + x > c) {
      days++;
      load = 0;
    }
    load += x;
  }

  return days;
}

int binarySearch(vector<int>& weights, int days) {
  int low = *max_element(weights.begin(), weights.end());
  int high = accumulate(weights.begin(), weights.end(), 0);

  while(low < high) {
    int mid = low + (high - low) / 2;

    if(daysNeededOptimal(weights, mid) <= days) high = mid;
    else low = mid+1;
  }
  return low;
}

int main() {
  vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int days = 5;

  // cout << daysNeeded(weights, days) << endl;

  cout << binarySearch(weights, days) << endl;
}