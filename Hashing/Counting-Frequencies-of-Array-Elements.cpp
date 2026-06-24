// Counting Frequencies of Array Elements

#include <bits/stdc++.h>
using namespace std;

void freq(vector<int>& arr, int n) {
    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    cout << "Frequencies: " << endl;
    for(auto i : mpp) {
        cout << i.first << " --> " << i.second << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    freq(arr, n);
    
}