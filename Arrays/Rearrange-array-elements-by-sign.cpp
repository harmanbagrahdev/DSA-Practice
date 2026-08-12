// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

// Brute force
// T = O(n + n/2)
// S = O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int>& arr) {
  vector<int> pos;
  vector<int> neg;

  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] > 0) pos.push_back(arr[i]);
    else neg.push_back(arr[i]);
  }

  for(int i = 0; i < arr.size() / 2; i++) {
    arr[2*i] = pos[i];
    arr[2*i + 1] = neg[i];
  }

  return arr;
}

int main() {
  vector<int> arr = {1,2,-4,-5};

  vector<int> ans = rearrange(arr);
  for(auto i : ans) {
    cout << i << " ";
  } cout << endl;
}