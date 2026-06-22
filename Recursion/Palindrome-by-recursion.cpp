// Check if String is Palindrome or Not

#include <bits/stdc++.h>
using namespace std;

string cleaned(string s) {
    string copy = s;
    string clean;

    for(auto ch : s) {
        if(isalnum(ch)) {
            clean += tolower(ch);
        }
    }
    return clean;
}

bool solve(string &s, int left, int right) {
    if(left >= (s.size() / 2)) return true;
    
    if(s[left] != s[right]) return false;

    return solve(s, left + 1, right - 1);
}

bool isPalindrome(string s) {
    s = cleaned(s);
    return solve(s, 0, s.size() - 1);
}


int main() {
    int left, right = 0;
    string s;
    getline(cin, s);
    
    if(isPalindrome(s)) {
        cout << "Palindrome\n";
    }
    else {
        cout << "Not a palindrome\n";
    }
}