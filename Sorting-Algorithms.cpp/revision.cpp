#include <bits/stdc++.h>
using namespace std;

class mS {
  public:
    void merge(vector<int>& arr, int low, int mid, int high) {
      vector<int> temp;
      int left = low, right = mid+1;

      while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
          temp.push_back(arr[left]);
          left++;
        }
        else {
          temp.push_back(arr[right]);
          right++;
        }
      }

      // Copy remaining elements
      while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
      }
      while(right <= high) {
        temp.push_back(arr[right]);
        right++;
      }

      // Copy sorted elements into original array
      for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
      }
    }

    void mergeSort(vector<int>& arr, int low, int high) {
      if(low >= high) return;

      int mid = (low + high) / 2;

      mergeSort(arr, low, mid);
      mergeSort(arr, mid + 1, high);

      merge(arr, low, mid, high);
    }
};

class qS {
  public:
    int partitionArr(vector<int>& arr, int low, int high) {
      int pivot = arr[low];
      int i = low, j = high;
    
      while(i < j) {
        while(arr[i] <= pivot && i <= high-1) i++;
    
        while(arr[j] > pivot && j >= low+1) j--;
    
        if(i < j) swap(arr[i], arr[j]);
      }
    
      swap(arr[low], arr[j]);
    
      return j;
    }
    
    void quickSort(vector<int>& arr, int low, int high) {
      if(low < high) {
        int partitionIndex = partitionArr(arr, low, high);
    
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
      }
    }
};

class selectionSort {
  public:
    void sS(vector<int> & arr) {
      int n = arr.size();
      for(int i = 0; i <= n-2; i++) {
        int mini = i; // assume current indexed element as minimum

        for(int j = i+1; j <= n-1; j++) {
          if(arr[j] < arr[mini]) {
            mini = j;
          }
        }

        swap(arr[mini], arr[i]);
      }
    }
};


int main() {
  vector<int> arr = {55,45,35,75,25,5};

  // qS qs;
  // qs.quickSort(arr, 0, arr.size()-1);

  // mS ms;
  // ms.mergeSort(arr, 0, arr.size()-1);

  selectionSort s;
  s.sS(arr);

  for(auto i : arr) {
    cout << i << " ";
  } cout << endl;
}