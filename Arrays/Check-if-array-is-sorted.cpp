// Check if array is sorted in ascending order or not

#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>& arr, int n) {
    for(int i = 0; i < n-1; i++) {
        if(arr[i] <= arr[i+1]) {
            
        }
        else return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array sorted in ascending order: ";
    int result = isSorted(arr, n);

    if(result == 0) cout << "False";
    else cout << "True";
}