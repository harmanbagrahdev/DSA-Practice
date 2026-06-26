// second largest element in array

// can be done by sorting 
// T = O(n^2)
// S = O(1)
#include <bits/stdc++.h>
using namespace std;

vector<int>& bubbleSort(vector<int>& arr, int n) {
    for(int i = 0; i <= n-1; i++) {

        for(int j = 0; j <= n-2; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    return arr;
}

int secLargestBySorting(vector<int>& arr, int n) {
    bubbleSort(arr, n);
    // return arr[n-2];
    return arr[n-2];
}

// T = O(n)
// S = O(1)
int second_largest(vector<int>& arr, int n) {
    int largest = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[largest]) {
            largest = i;
        }
    }

    // vector<int> diff(n);
    // for(int i = 0; i < n; i++) {
    //     diff[i] = arr[largest] - arr[i];
    // }

    int min_diff = -1; // no valid index
    for(int i = 0; i < n; i++) {
        // if(diff[i] < diff[min_diff] && diff[i] != 0) {
        //     min_diff = i;
        // }
        
        // if(diff[i] == 0) continue; // skip largest element
        
        // if no valid index found, then replace min_diff with current index. If already some difference is initialised previously then check other index for min element!!
        
        // if(min_diff == -1 || diff[i] < diff[min_diff]) { 
            //     min_diff = i;
            // }
            
        if(i == largest) continue; // skip largest element
                        //   largest      -  current <  largest  - element yet known with min_diff
        if(min_diff == -1 || arr[largest] - arr[i] < arr[largest] - arr[min_diff]) { 
            min_diff = i;
        }
    }

    // int sec_largest = arr[min_diff];

    // return sec_largest;

    return arr[min_diff];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Second largest element in array : " << second_largest(arr, n) << endl;
    cout << "Second largest element in array : " << secLargestBySorting(arr, n) << endl; 

}