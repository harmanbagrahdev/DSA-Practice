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

bool isPalindrome(string s) {
    s = cleaned(s);
    int n = s.size();

    for(int i = 0; i <= (n / 2); i++) {
        if(s[i] != s[n - i - 1]) return false;
    }
    
    return true;
}


int main() {
    string s;
    getline(cin, s);
    
    if(isPalindrome(s)) {
        cout << "Palindrome\n";
    }
    else {
        cout << "Not a palindrome\n";
    }
}