#include <bits/stdc++.h>
using namespace std;

// T = O( n * (2^n) * log((2^n)) ) => O( (n^2) * (2^n) )
// S = O(n * (2^n))
class Solution
{
public:
  void generateAllSubsets(int index, vector<int> &nums, vector<int> &current, set<vector<int>> &uniqueSubsets)
  {
    // Base case: when we've considered all elements
    if (index == nums.size())
    {
      // Sort the subset so order doesn't create "fake" unique sets
      vector<int> sortedSubset = current;
      sort(sortedSubset.begin(), sortedSubset.end());
      uniqueSubsets.insert(sortedSubset);
      return;
    }

    // Choice 1: Exclude the current element
    generateAllSubsets(index + 1, nums, current, uniqueSubsets);

    // Choice 2: Include the current element
    current.push_back(nums[index]);
    generateAllSubsets(index + 1, nums, current, uniqueSubsets);
    current.pop_back(); // Backtrack
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    set<vector<int>> uniqueSubsets;
    vector<int> current;

    // Generate every combination blindly
    generateAllSubsets(0, nums, current, uniqueSubsets);

    // Convert the set back to a vector of vectors
    return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
  }
};

int main()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  Solution s;
  vector<vector<int>> res = s.subsetsWithDup(nums);

  for (auto row : res)
  {
    cout << "[";
    for (auto el : row)
    {
      cout << el << " ";
    }
    cout << "]" << endl;
  }

  cout << endl;
}