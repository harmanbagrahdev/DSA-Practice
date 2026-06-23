// n to 1

#include <bits/stdc++.h>
using namespace std;

int num(int n) {
    if(n == 1) return 1;

    cout << n << " ";
    return num(n-1);
}

int main() {
    int n;
    cin >> n;

    cout << num(n);
}