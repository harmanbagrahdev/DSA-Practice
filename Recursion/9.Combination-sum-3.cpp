#include <bits/stdc++.h>
using namespace std;

// T = O((2^9) * k) => O(1)
// S = O(k)
class Solution
{
public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<vector<int>> ans;
    // Total subsets of numbers 1..9 is 2^9 = 512
    for (int mask = 0; mask < (1 << 9); ++mask)
    {
      vector<int> temp;
      int sum = 0;
      for (int i = 0; i < 9; ++i)
      {
        if ((mask & (1 << i)))
        {
          temp.push_back(i + 1);
          sum += (i + 1);
        }
      }
      if (temp.size() == k && sum == n)
      {
        ans.push_back(temp);
      }
    }
    return ans;
  }
};

int main()
{
  int k, n;
  cin >> k >> n;

  Solution s;
  vector<vector<int>> res = s.combinationSum3(k, n);

  cout << "[";
  for (auto row : res)
  {
    cout << "[";
    for (auto el : row)
    {
      cout << el << " ";
    }
    cout << "]";
  }
  cout << "]" << endl;
}