#include <bits/stdc++.h>
using namespace std;

// Linear Search

int linearSearch(vector<int>& arr, int n) {
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] == n) {
      return i;
      break;
    }
  }
  return -1;
}

int main() {
    vector<int> arr = {0,1,2,3,4,5,10,12,45,1,20,5};
    int n;
    cout << "Enter number to find : ";
    cin >> n;

    cout << "Searching index of " << n << " in array : ";
    cout << linearSearch(arr, n);
    cout << endl;
}