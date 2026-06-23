// n to 1 by backtracking

#include <bits/stdc++.h>
using namespace std;

void num(int n) {
    if(n == 0) return;
    
    num(n - 1);
    cout << n << " "; // backtracking
}

int main() {
    int n;
    cin >> n;

    num(n);
}