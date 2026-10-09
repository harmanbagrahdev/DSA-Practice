// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Also contains a subset generation utility.

#include <bits/stdc++.h>
using namespace std;

// Brute force for Generate Parentheses
// T = O(n * (2^(2n))) 
// S = O(n)
class Solution
{
public:
  vector<string> generateParenthesis(int n)
  {
    vector<string> res;
    string current = "";
    generateAll(current, 2 * n, res);

    return res;
  }

  void generateAll(string &current, int length, vector<string> &res)
  {
    if (current.length() == length)
    {
      if (isValid(current))
      {
        res.push_back(current);
      }

      return;
    }

    current.push_back('(');
    generateAll(current, length, res);
    current.pop_back();

    current.push_back(')');
    generateAll(current, length, res);
    current.pop_back();
  }

  bool isValid(string &str)
  {
    int balance = 0;
    for (char c : str)
    {
      if (c == '(')
        balance++;
      else
        balance--;
      if (balance < 0)
        return false;
    }

    return balance == 0;
  }
};

// Optimal Backtracking for Subsets
// T = O(n * (2^n))
// S = O(n)
class OptimalSolution {
  public : 
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> result;
      vector<int> current;
      backtrack(0, nums, current, result);
      return result;
    }

    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
      result.push_back(current);

      for (int i = index; i < nums.size(); ++i) {
        current.push_back(nums[i]);       
        backtrack(i + 1, nums, current, result); 
        current.pop_back();              
      }
    }
};

int main()
{
  int size;
  cout << "Enter number of elements for subsets: ";
  if (!(cin >> size)) return 0;

  vector<int> nums;
  cout << "Enter elements: ";
  for(int i = 0; i < size; i++) {
    int val;
    cin >> val;
    nums.push_back(val); // Corrected dynamic input allocation
  }

  OptimalSolution os;
  vector<vector<int>> ans = os.subsets(nums);
  
  cout << "\nGenerated Subsets:\n";
  for (const auto& row : ans)
  {
    cout << "[ ";
    for(auto x : row) {
      cout << x << " ";
    }
    cout << "]\n";
  }
  return 0;
}