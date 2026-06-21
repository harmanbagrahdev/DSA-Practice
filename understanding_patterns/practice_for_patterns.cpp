#include<bits/stdc++.h>
using namespace std;

void diamond(int n) {
    for(int i = 1; i <= 2*n - 1; i++) {

        int stars = i; // row no.
        
        if(i > n) {
            stars = 2*n - i; // also row no.
        }

        int spaces = n - stars;

        //spaces
        for(int j = 1; j <= spaces; j++) {
            cout << " ";
        }

        //stars
        for(int k = 1; k <= 2*stars - 1 /* width */; k++) {
            if(k == 1 || k == 2*stars - 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    //cout << "Enter n: ";
    //cin >> n;

    diamond(n);
}