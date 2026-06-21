// Reverse a number

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int revNum = 0;
    while(n > 0) {
        int temp = n % 10;
        revNum = 10 * revNum + temp;
        n /= 10;
    }

    cout << revNum << endl;
}