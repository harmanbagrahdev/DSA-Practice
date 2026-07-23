#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& arr, int n) {
    // traverse through whole array
    for(int i = 0; i <= n - 2; i++) {
        int min = i; // assume current indexed element as minimum

        // traverse through unsorted part
        for(int j = i + 1; j <= n - 1; j++) {
            if(arr[j] < arr[min]) { // check and update min
                min = j;
            }
        }

        // swap
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    // print sorted array
    for(int i = 0; i <= n-1; i++) {
        cout << arr[i] << " ";
    }
}


void bubble_sort(vector<int>& arr, int n) {
    // traverse array
    for(int i = 0; i <= n-1; i++) {
        bool swap = false;

        // check and swap adjacent elements
        for(int j = 0; j <= n-2; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j+1] = arr[j];
                arr[j] = temp;
                swap = true;
            }
        }

        // for optimal case exit loop with one iteration when array is sorted
        if(!swap) {
            break;
        }

        cout << "run" << endl; // checking number of iterations
    }

    // print sorted array
    for(int i = 0; i <= n-1; i++) {
        cout << arr[i] << " ";
    }
}

void insertion_sort(vector<int>& arr, int n) { // O(n^2)
    // traverse through array
    for(int i = 1; i <= n-1; i++) {
        int key = arr[i]; // Current element as key 
        int j = i-1;

        // Shift elements that are greater than key by one position
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key; // Insert key at correct position
    }

    // print sorted array
    for(int i = 0; i <= n-1; i++) {
        cout << arr[i] << " ";
    }
}

// T = O( n * log(n) )
// S = O(n)
class Solution {
public:
    // Function to merge two halves of the array
    void merge(vector<int>& arr, int low, int mid, int high) {
        // temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    // Recursive merge sort function
    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high)
            return;

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);

        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
};


// T = O( n * log(n) )
// S = O(1)

int partitionArr(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivot

    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);

    return i+1; // return pivotIndex
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionArr(arr, low, high); // find pivot index

        quickSort(arr, low, pivotIndex - 1); // sort before pivot

        quickSort(arr, pivotIndex + 1, high); // sort after pivot
    }
}


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i <= n-1; i++) {
        cin >> arr[i];
    }

    // selection_sort(arr, n);
    // bubble_sort(arr, n);
    // insertion_sort(arr, n);
    
    // Solution s;
    // s.mergeSort(arr, 0, arr.size()-1);
    // for(auto i : arr) {
    //     cout << i << " ";
    // }
    // cout << endl;

    quickSort(arr, 0, arr.size()-1);
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Program completed successfully.\n";
}