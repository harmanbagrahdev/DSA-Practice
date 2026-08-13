// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

#include <bits/stdc++.h>
using namespace std;

// Brute force
// T = O(n + n/2)
// S = O(n)
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

// Optimal Solution
// T = O(n) --> slightly better from brute
// S = O(n)
vector<int> rearrangeOptimal(vector<int>& arr) {
  int n = arr.size();
  int pos = 0, neg = 1;
  vector<int> ans(n, 0);

  for(int i = 0; i < n; i++) {
    if(arr[i] > 0) {
      ans[pos] = arr[i];
      pos += 2;
    }

    else if(arr[i] < 0) {
      ans[neg] = arr[i];
      neg += 2;
    }
  }

  return ans;
}

// If number of positive and negative elements are not equal : this becomes the optimal approach
// T = O(2*n)
// S = O(n)
vector<int> rearrangeArray(vector<int>& arr) {
  int n = arr.size();
  vector<int> pos;
  vector<int> neg;
  
  for(int i = 0; i < n; i++) {
    if(arr[i] > 0) pos.push_back(arr[i]);
    else neg.push_back(arr[i]);
  }
  
  int posSize = pos.size();
  int negSize = neg.size();

  if(posSize > negSize) {
    for(int i = 0; i < negSize; i++) {
      arr[2*i] = pos[i];
      arr[2*i + 1] = neg[i];
    }
  
    int index = negSize * 2;
    for(int i = negSize; i < posSize; i++) {
      arr[index] = pos[i];
      index++;
    }
  }

  else {
    for(int i = 0; i < posSize; i++) {
      arr[2*i] = pos[i];
      arr[2*i + 1] = neg[i];
    }

    int index = posSize * 2;
    for(int i = posSize; i < negSize; i++) {
      arr[index] = pos[i];
      index++;
    }
  }


  return arr;   
}


int main() {
  vector<int> arr = {1,2,-4,-5,8,6,4};

  // vector<int> ans = rearrange(arr);

  // vector<int> ans = rearrangeOptimal(arr);

  vector<int> ans = rearrangeArray(arr);

  for(auto i : ans) {
    cout << i << " ";
  } cout << endl;
}