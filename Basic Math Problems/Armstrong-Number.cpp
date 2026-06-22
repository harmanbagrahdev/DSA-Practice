// Check if the Number is Armstrong

#include <iostream>
using namespace std;

void armstrong_no(int n) {
    int copy = n;
    int sum = 0;
    while(n > 0) {
        int lastDigitCube = (n % 10) * (n % 10) * (n % 10);
        sum += lastDigitCube;
        n /= 10;
    }
    if(copy == sum) cout << "Number is palindrome\n";
    else cout << "Not palindrome\n";
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    armstrong_no(n);
}