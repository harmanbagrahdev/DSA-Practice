// Provided with a goal integer target and an array of unique integers nums, provide a list of all possible combinations of nums in which the selected numbers add up to the target. The combinations can be returned in any order.

// A number may be selected from nums an infinite number of times. There are two distinct combinations if the frequency of at least one of the selected numbers differs.

// The test cases are created so that, for the given input, there are fewer than 150 possible combinations that add up to the target.

// If there is no possible combination, then return an empty vector.

#include <bits/stdc++.h>
using namespace std;

// T = O(exponential) => O((2^t) * k) ---> k is avg length of pairs generated
// S = O(hypothetical --> depends on number of pairs) => O(k * x)  ---> x is number of pairs
class Solution
{
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<vector<int>> ans;
    vector<int> ds;

    findCombinations(0, target, candidates, ans, ds);
    return ans;
  }

  void findCombinations(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
  {
    if (index == arr.size())
    {
      if (target == 0)
      {
        ans.push_back(ds);
      }
      return;
    }

    if (arr[index] <= target)
    {
      ds.push_back(arr[index]);
      findCombinations(index, target - arr[index], arr, ans, ds);
      ds.pop_back();
    }

    findCombinations(index + 1, target, arr, ans, ds);
  }
};

int main() {
  Solution s;
  vector<int>  nums = {2, 3, 5, 4};
  int target = 7;
  vector<vector<int>> res = s.combinationSum(nums, target);

  for(auto row : res) {
    for(auto el : row) {
      cout << el << " ";
    }
    cout << endl;
  }

  cout << endl;
}