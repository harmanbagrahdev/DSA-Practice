#include <bits/stdc++.h>
using namespace std;

// T = O()
// S = O(1)
string binarySearch(vector<int>& arr, int target) {
  int n = arr.size();
  int start = 0;
  int end = n-1;
  int mid = (start + end) / 2;

  while(start <= end && arr[mid] != target) {
    if(target < arr[mid]) {
      end = mid-1;
    }
    else {
      start = mid + 1;
    }

    mid = (start + end) / 2;
  }

  if(arr[mid] == target) {
    cout << mid << endl;
    return "found";
  }

  return "not found";
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  cout << "Enter array elements : ";
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int target;
  cout << "Enter an element to search in array : ";
  cin >> target;

  cout << binarySearch(arr, target) << endl;
}