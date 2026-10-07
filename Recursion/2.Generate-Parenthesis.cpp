// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include <bits/stdc++.h>
using namespace std;

//  T = O(n * (2^n))
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

int main()
{
  int n;
  cin >> n;

  Solution s;
  vector<string> ans = s.generateParenthesis(n);
  for (auto x : ans)
  {
    cout << x << " ";
  }
  cout << endl;
}