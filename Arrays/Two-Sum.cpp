// Given an array of integers arr[] and an integer target.
// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
// 2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n^2)
// S = O(1)
// 1st variety
vector<int> twoSumByIndeces(vector<int>& arr, int n) {
  vector<int> index;

  for(int i = 0; i < arr.size(); i++) {
    int firstNum = arr[i];
    for(int j = i+1; j < arr.size(); j++) {
      if(firstNum + arr[j] == n) {
        return{i, j};
      }
    }
  }
  return {-1, -1};
}

// 2nd variety
string twoSumString(vector<int>& arr, int n) {
  for(int i = 0; i < arr.size(); i++) {
    int firstNum = arr[i];
    for(int j = i+1; j < arr.size(); j++) {
      if(firstNum + arr[j] == n) return "yes";
    }
  }
  return "no";
}

// Better Solution : hashing
// T = O(n * log(n) ) --> for ordered map
// S = O(n)
string twoSumBetter(vector<int>& arr, int n) {
  map<int, int> mpp;

  for(int i = 0; i < arr.size(); i++) {
    int a = arr[i];
    int more = n - a;

    if(mpp.find(more) != mpp.end()) return "Yes"; // or return {mpp[more], i};

    mpp[a] = i;
  }
  return "No";
}

// Optimal Solution (for variety 1 only and not for variety 2 as it will use extra space): two pointer and greedy approach
// T = O(n * log(n) ) {for sorting} + O(n)
// S = O(1) --> if there is no constraint on changing the array otherwise S = O(n)
string twoSumOptimal(vector<int>& arr, int n) {
  // sorted array needed
  sort(arr.begin(), arr.end());
  
  int left = 0, right = arr.size()-1;

  while(left <= right) {
    int sum = arr[left] + arr[right];

    if(sum == n) {
      return "Yes";
    }
    else if(sum < n) {
      left++;
    }
    else if(sum > n) {
      right--;
    }
  }
  return "No";
}

int main() {
  vector<int> arr = {2,6,5,8,11};
  int n = 14;
  
  // cout << twoSumString(arr, n) << endl;

  // vector<int> index = twoSumByIndeces(arr, n);

  // for(auto i : index) {
  //   cout << i << " ";
  // } cout << endl;

  // cout << twoSumBetter(arr, n) << endl;

  cout << twoSumOptimal(arr, n) << endl;
}