// Check if the Array is Sorted 2

#include <bits/stdc++.h>
using namespace std;

// rotate array
void rotate(vector<int>& arr, int n) {
    int temp = arr[0];

    for(int i = 0; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;

    for(auto i : arr) {
        cout << i << " ";
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Rotated array: \n";
    rotate(arr, n);
}