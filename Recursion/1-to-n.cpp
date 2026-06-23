// Print 1 to n

#include <iostream>
using namespace std;

void num(int m, int n) {
    if(m > n) return;
    cout << m << " ";
    return num(m + 1, n);
}

int main() {
    int n;
    cin >> n;

    num(1, n);
}