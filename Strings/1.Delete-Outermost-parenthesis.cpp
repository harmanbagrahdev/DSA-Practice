// A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

// For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
// A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

// Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

// Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
#include <bits/stdc++.h>
using namespace std;

string removeOuterParenthesis(string s) {
  int depth = 0;
  string ans = "";

  for(char c : s) {
    if(c == '(') {
      if(depth > 0) ans += c;
      depth++;
    }
    else {
      depth--;
      if(depth > 0) ans += c;
    }
  }

  return ans;
}

int main() {
  string s = "(()())(())(()(()))";

  cout << removeOuterParenthesis(s) << endl;
}