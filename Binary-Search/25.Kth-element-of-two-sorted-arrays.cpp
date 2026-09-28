// Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O((m+n) * log(m+n)) + 2 * O(min(m, n))
// S = O(min(m, n)) --> extra space
int kthElementBrute(vector<int>& a, vector<int>& b, int k) {
  if(b.size() < a.size()) return kthElementBrute(b, a, k);
  int m = a.size(), n = b.size();

  int i = 0;
  while(i < m) {
    b.push_back(a[i++]);
  }
  sort(b.begin(), b.end()); // O(m+n)

  for(int i = 0; i < m+n; i++) {
    if(i == k-1) {
      return b[k-1];
      break;
    }
  }

  return -1;
}

// Better solution
// T = O(m+n)
// S = O(m+n) --> worst case
int kthElementBetter1(vector<int>& a, vector<int>& b, int k) {
  int m = a.size(), n = b.size();
  vector<int> temp; // we can also solve this without storing anything and by just using cnt variable!

  int i = 0, j = 0;
  int cnt = 0;
  while(i < m && j < n) {
    
    if(a[i] <= b[j]) {
      temp.push_back(a[i++]);
      if(cnt == k-1) return temp[k-1];
      cnt++;
    }
    else {
      temp.push_back(b[j++]);
      if(cnt == k-1) return temp[k-1];
      cnt++;
    }
  }

  while(i < m) {
    temp.push_back(a[i++]);
    if(cnt == k-1) return temp[k-1];
    cnt++;
  }
  while(j < n) {
    temp.push_back(b[j++]);
    if(cnt == k-1) return temp[k-1];
    cnt++;
  }

  // for(int i = 0; i < m+n; i++) {
  //   if(i == k-1) return temp[k-1];
  // }

  return -1;
}

// T = O(k)
// S = O(1)
int kthElementBetter2(vector<int>& a, vector<int>& b, int k) {
  int m = a.size(), n = b.size();
  if(k < 1 || k > m+n) return -1;

  int i = 0, j = 0, cnt = 0;
  while(i < m && j < n) {
    if(a[i] <= b[j]) {
      if(cnt == k-1) return a[i];
      i++;
    }
    else {
      if(cnt == k-1) return b[j];
      j++;
    }
    cnt++;
  }

  while(i < m) {
    if(cnt == k-1) return a[i];
    i++;
    cnt++;
  }
  while(j < n) {
    if(cnt == k-1) return b[j];
    j++;
    cnt++;
  }

  return -1;
}

// T = O( log( min(m, n) ) )
// S = O(1)
int kthElementOptimal(vector<int>& a, vector<int>& b, int k) {
  if(b.size() < a.size()) return kthElementOptimal(b, a, k);
  int m = a.size(), n = b.size();

  int low = max(0, k - n), high = min(k, m);

  while(low <= high) {
    int p1 = (low + high) / 2; // partition in first array
    int p2 = k - p1; // partition in second array

    int left1 = p1 == 0 ? INT_MIN : a[p1 - 1];
    int left2 = p2 == 0 ? INT_MIN : b[p2 - 1];

    int right1 = p1 == m ? INT_MAX : a[p1];
    int right2 = p2 == n ? INT_MAX : b[p2];

    if(left1 <= right2 && left2 <= right1) { // to check if valid
      return max(left1, left2);
    }

    else if(left1 > right2) high = p1-1;
    else low = p1+1;
  }

  return -1;
}

int main() {
  vector<int> a = {2, 3, 6, 7, 9}, b = {1, 4, 8, 10};
  int k = 5;

  // cout << kthElementBrute(a, b, k) << endl;

  // cout << kthElementBetter1(a, b, k) << endl;

  // cout << kthElementBetter2(a, b, k) << endl;

  cout << kthElementOptimal(a, b, k) << endl;
}