// rotate array
#include <bits/stdc++.h>
using namespace std;

// right rotation
void rightRotate(vector<int> arr, int n) {
    int temp = arr[n-1];

    for(int i = n-1; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;

    for(auto i : arr) {
        cout << i << " ";
    }
}

// left rotation
void leftRotate(vector<int> arr, int n) {
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

    cout << "Right rotated array: \n";
    rightRotate(arr, n);

    cout << endl;

    cout << "Left rotated array: \n";
    leftRotate(arr, n);
}