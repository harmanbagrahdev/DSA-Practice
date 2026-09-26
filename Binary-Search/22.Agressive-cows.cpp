// You are given an array arr of size N which denotes the position of stalls.
// You are also given an integer k which denotes the number of Aggressive Cows.
// You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.

#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& s, int k, int d) {
  // The first cow is placed at the first stall to leave maximum room for the remaining cows.
  int cowsPlaced = 1;
  int lastPos = s[0];

  for(int i = 1; i < s.size(); i++) {
    if(s[i] - lastPos >= d) {
      cowsPlaced++;
      lastPos = s[i];
    }

    if(cowsPlaced >= k) return true;
  }

  return false;
}

int maxMinDistance(vector<int>& s, int k) {
  int n = s.size();
  sort(s.begin(), s.end());
  int maxDistance = s.back() - s.front();

  for(int d = 1; d <= maxDistance; d++) {
    if(!canPlace(s, k, d)) return d - 1;
  }

  return maxDistance;
}

// Optimal Solution
// T = O()
// S = O()
int maxMinDistanceOptimal(vector<int>& s, int k) {
  sort(s.begin(), s.end());
  int low = 1;
  int high = s.back() - s.front();

  while(low <= high) {
    int mid = (low + high) / 2;
  
    if(canPlace(s, k, mid)) {
      low = mid+1;
    }
    else {
      high = mid-1;
    }
  }

  return high;
}

int main() {
  vector<int> stalls = {1, 2, 4, 8, 9};
  int k = 3;

  cout << maxMinDistance(stalls, k) << endl;

  // cout << maxMinDistanceOptimal(stalls, k) << endl;
}