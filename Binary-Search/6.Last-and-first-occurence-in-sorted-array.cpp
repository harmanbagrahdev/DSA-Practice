// Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key.
// If the target is not found then return -1.
// Note: Consider 0 based indexing

#include <bits/stdc++.h>
using namespace std;

// My Solution
// T = O(2 * n)
// S = O(1) --> auxilliary space
vector<int> lastOccurence(vector<int> &nums, int &target)
{
  int n = nums.size();
  vector<int> ans = {-1, -1};

  for (int i = 0; i < n; i++)
  {
    if (nums[i] == target)
    {
      ans[0] = i;
      break;
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    if (nums[i] == target)
    {
      ans[1] = i;
      break;
    }
  }

  return ans;
}

// Optimal solution
// T = O(2 * log(n))
// S = O(1)
void bs(vector<int>& nums, int& target, int& el, bool findFirst) {
  int n = nums.size();
  int low = 0, high = n - 1;
  
  while (low <= high)
  {
    int mid = (low + high) / 2;
    
    if (target == nums[mid])
    {
      el = mid;
      if(findFirst) high = mid-1;
      else low = mid + 1;
    }
    else if (target > nums[mid])
    {
      low = mid + 1;
    }
    else high = mid - 1;
  }
  
  // ans.push_back(el);
}

vector<int> lastOccurenceOptimal(vector<int> &nums, int &target) {
  int first = -1;
  int last = -1;
  vector<int> ans;

  bs(nums, target, last, true);
  bs(nums, target, first, false);

  ans.push_back(first);
  ans.push_back(last);

  return ans;
}

int main()
{
  vector<int> nums = {3, 4, 13, 13, 13, 20, 40};
  int target = 13;

  // vector<int> ans = lastOccurence(nums, target);
  vector<int> ans = lastOccurenceOptimal(nums, target);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}