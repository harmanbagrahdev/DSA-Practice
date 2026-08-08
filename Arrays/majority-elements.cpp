// Given an integer array nums of size n, return the majority element of the array.
// The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.

#include <bits/stdc++.h>
using namespace std;

// My solution : Better solution
// T = O(2 * n) --> worst case
// S = O(n) --> worst case
int majorityElement(vector<int>& arr) {
  int n = arr.size();
  unordered_map<int, int> mpp;

  for(int i = 0; i < n; i++) {
    mpp[arr[i]]++;
  }

  for(auto i : mpp) {
    if(i.second > n/2) return i.first;
  }

  return -1;
}

// Brute
// T = O(n^2)
// S = O(1)
int majorityElementBrute(vector<int>& arr) {
  for(int i = 0; i < arr.size(); i++) {
    int current = 0; // current element count

    for(int j = i; j < arr.size(); j++) {
      if(arr[j] == arr[i]) current++;
    }

    if(current > (arr.size() / 2) ) return arr[i];
  }

  return -1;
}

// Optimal solution : Moore's Voting Algorithm
// T = O(2*n)
// S = O(1)
int majorityElementOptimal(vector<int>& arr) {
  int n = arr.size();
  int cnt = 0;
  int el; // element

  // Moore's algorithm
  for(int i = 1; i < n; i++) {
    if(cnt == 0) {
      el = arr[i];
      cnt = 1;
    }

    else if(el == arr[i]) cnt++;

    else if(el != arr[i]) cnt--;
  }

  // Verify element occurs more than n/2 : This step is needed only when there is no surity that an array do have a majority element!
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(el == arr[i]) count++;
  }

  if(count > n/2) return el;

  return -1;
}
int main() {
  vector<int> arr = {1, 1, 1, 2, 1, 2};

  // cout << majorityElement(arr) << endl;

  // cout << majorityElementBrute(arr) << endl;

  cout << majorityElementOptimal(arr) << endl;
}