// Count all Digits of a Number

#include <bits/stdc++.h>

using namespace std;

int count_digits(int &n) {
    int count = 0;
    if(n == 0) return 1;

    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << count_digits(n);
}