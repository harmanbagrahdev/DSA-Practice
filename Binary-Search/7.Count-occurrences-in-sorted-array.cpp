// You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

#include <bits/stdc++.h>
using namespace std;

// Brute
// T= O(n)
// S = O(1)
int cntOccurrence(vector<int>& nums, int& x) {
  int n = nums.size();
  int cnt = 0;

  for(int i = 0; i < n; i++) {
    if(nums[i] == x) cnt++;
  }

  return cnt;
}

// Optimal : occurrences = (last occurrence - first occurrence) + 1
// T= O(log(n))
// S = O(1)
void bs(vector<int>& nums, int& x, int& el, bool ifFirst) {
  int n = nums.size();
  int low = 0, high = n-1;
  
  while(low <= high) {
    int mid = (low + high) / 2;

    if(nums[mid] == x) {
      el = mid;
      if(ifFirst) high = mid-1;
      else low = mid+1;
    }
    else if(x > nums[mid]) low = mid+1;
    else high = mid-1;
  }
}

vector<int> firstAndLast(vector<int>& nums, int& x) {
  vector<int> ans;

  int first = -1;
  int last = -1;

  bs(nums, x, first, true);
  if(first == -1) return {-1, -1};
  bs(nums, x, last, false);

  ans.push_back(first);
  ans.push_back(last);

  return ans;
}

int cntOccurrenceOptimal(vector<int>& nums, int& x) {
  vector<int> ans = firstAndLast(nums, x);
  int res = (ans[1] - ans[0]) + 1;

  return res;
}

int main() {
  vector<int> nums = {2, 2 , 3 , 3 , 3 , 3 , 4};
  int x = 2;

  // cout << cntOccurrence(nums, x) << endl;

  cout << cntOccurrenceOptimal(nums, x) << endl;
}