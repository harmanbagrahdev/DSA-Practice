// Sum of first n natural numbers

#include <bits/stdc++.h>
using namespace std;

// O(n)
int sum(int n) {
    if(n == 0) return 0;

    cout << n << " ";

    return n + sum(n-1);
}

// O(1)
int sum_easy(int n) {
    return n*(n+1) / 2;
}


int main() {
    int n;
    cin >> n;

    cout << "Sum: " << sum(n) << endl;
    cout << "Sum by formula: " << sum_easy(n) << endl;
}