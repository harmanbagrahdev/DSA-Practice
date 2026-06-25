// second largest element in array

// can be done by sorting 

#include <bits/stdc++.h>
using namespace std;

// mistakes
vector<int> bubbleSort(vector<int>& arr, int n) {
    for(int i = 0; i <= n-1; i++) {

        for(int j = i; i <= n-2; i++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    return arr;
}

void secLargestBySorting(vector<int>& arr, int n) {
    arr = bubbleSort(arr, n);
    // return arr[n-2];
    for(auto i: arr) {
        cout << i << " ";
    }
}

// Some bugs may be present!
int second_largest(vector<int>& arr, int n) {
    int largest = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[largest]) {
            largest = i;
        }
    }

    vector<int> diff(n);
    for(int i = 0; i < n; i++) {
        diff[i] = arr[largest] - arr[i];
    }

    int min_diff = -1;
    for(int i = 0; i < n; i++) {
        if(diff[i] < diff[min_diff] && diff[i] != 0) {
            min_diff = i;
        }
        
        // if(diff[i] == 0) continue;
        // if(min_diff == -1 || diff[i] < diff[min_diff]) {
        //     min_diff = i;
        // }
    }

    int sec_largest = arr[min_diff];

    return sec_largest;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // cout << "Second largest element in array : " << second_largest(arr, n) << endl;
    // cout << "Second largest element in array : " << secLargestBySorting(arr, n) << endl;
    secLargestBySorting(arr, n);

}