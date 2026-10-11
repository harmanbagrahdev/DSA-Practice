#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
  }

  void findCombination(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
  {
    if (target == 0)
    {
      ans.push_back(ds);
      return;
    }

    for (int i = index; i < arr.size(); i++)
    {
      if (i > index && arr[i] == arr[i - 1])
        continue;
      if (arr[i] > target)
        break;
      ds.push_back(arr[i]);
      findCombination(i + 1, target - arr[i], arr, ans, ds);
      ds.pop_back();
    }
  }
};

int main()
{
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;

  Solution s;
  vector<vector<int>> res = s.combinationSum2(candidates, target);

  for (auto row : res)
  {
    for (auto el : row)
    {
      cout << el << " ";
    }
    cout << endl;
  }

  cout << endl;
}