#include <bits/stdc++.h>
using namespace std;

// but this will not work if same elements are not consecutive

// int appearedOnce(vector<int>& arr, int n) {
//   for(int i = 0; i < n-1; i += 2) {
//     if(arr[i] != arr[i+1]) {
//       return arr[i]; // return that element
//     }
//   }

//   return arr[n-1]; // return last element if all others are paired
// }


// brute --> by linear search
// T = O(n^2)
// S = O(1)
int appearedOnce(vector<int>& arr, int n) {
  for(int i = 0; i < n; i++) {
    int num = arr[i];
    int count = 0;

    for(int j = 0; j < n; j++) {
      if(num == arr[j]) count++;
    }
    
    if(count == 1) return num;
  }

  return -1;
}

int main() {
  vector<int> arr = {1,1,2,2,3,3,4,4,5,6,6};
  int n = arr.size();

  cout << appearedOnce(arr, n) << endl;
}