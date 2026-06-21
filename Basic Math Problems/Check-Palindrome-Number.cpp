// Check if a number is palindrome

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int original = n;

    int revNum = 0;
    while(n > 0) {
        int temp = n % 10;
        revNum = revNum * 10 + temp;
        n /= 10;
    }
    if(original == revNum) {
        cout << "Number is Palindrome\n";
    }
    else {
        cout << "Not Palindrome\n";
    }
}