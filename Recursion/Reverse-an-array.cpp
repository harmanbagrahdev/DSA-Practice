// Reverse an array

#include <bits/stdc++.h>
using namespace std;

void reverse(int a[], int left, int right) {
    if(left >= right) return;
    
    swap(a[left], a[right]);

    reverse(a, left + 1, right - 1);
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter array elements: ";
    int a[n];
    for(auto i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    reverse(a, 0, n-1);

    cout << "Array: ";
    for(auto i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

}