// largest element in array

#include <bits/stdc++.h>
using namespace std;

int largest(vector<int>& arr, int n) {
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[max]) {
            max = i;
        }
    }

    return arr[max];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Largest element in array is : " << largest(arr, n) << endl;
}