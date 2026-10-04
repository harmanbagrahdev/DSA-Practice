#include <bits/stdc++.h>
using namespace std;

// T = O(s.length())
// S = O(1)
int romanToInteger(string s) {
  unordered_map<char, int> l = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
  };
  int ans = 0;

  for(int i = 0; i < s.size(); i++) {
    if(i+1 < s.size() && l[s[i]] < l[s[i+1]]) ans -= l[s[i]];
    else ans += l[s[i]];
  }
  
  return ans;
}

int main() {
  string s = "MCMXCIV";

  cout << romanToInteger(s) << endl;
}