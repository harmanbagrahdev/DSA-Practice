// GCD of Two Numbers

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int gcd(int &x, int &y) {
    while(y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int Rec_gcd(int x, int y) {
    if(y == 0) return x;
    return Rec_gcd(y, x % y);
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    
    cout << "GCD: " << gcd(x,y) << endl;
    cout << "GCD by recursive function: " << Rec_gcd(x,y) << endl;
    

    // int ans = gcd(18, 12); // built in function in numeric library! new compiler required! (c++17)
    // cout << ans; 

    cout << __gcd(18, 12) << endl; // 6  Use __gcd() in CP
}

