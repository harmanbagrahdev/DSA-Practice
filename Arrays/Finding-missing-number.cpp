#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // brute --> find missing number by linear search
    // T = O(n^2)
    // S = O(1)
    int missing(vector<int>& arr, int n) {
      for(int i = 1; i <= n; i++) {
        int flag = 0;
        
        // size of array is n-1 as one number is missing
        for(int j = 0; j < n-1; j++) {
          if(arr[j] == i) {
            flag = 1;
            break;
          }
        }

        if(flag == 0) {
          return i;
        }
      }
      return -1;
    }

    // better --> use a hash array
    // T = O(2 * n)
    // S = O(n)
    int missingByHashing(vector<int>& arr, int n) {
      vector<int> hash(n+1, 0);

      for(int i = 0; i < n-1; i++) {
        hash[arr[i]] = 1; // marked as present in hash array
      }

      for(int i = 1; i <= n; i++) {
        if(hash[i] == 0) return i;
      }

      return -1;
    }

    // Optimal --> There are two optimal solutions sum method and xor method : 

    // sum method
    // T = O(n)
    // S = O(1)
    int missingBySum(vector<int>& arr, int n) {
      int sum1 = n * (n+1) / 2;
      int sum2 = 0;

      for(int i = 0; i < n-1; i++) {
        sum2 += arr[i];
      }

      return (sum1 - sum2);
    }

    // XOR method : slightly better than sum method because integer overflow can occur in sum method
    // T = O(n)
    // S = O(1)

    // xor of two same numbers is zero, and xor of zero with some number = some number
    int missingByXOR(vector<int>& arr, int N) {
      int xor1 = 0, xor2 = 0;
      int n = N-1;

      for(int i = 0; i < n; i++) {
        xor2 = xor2 ^ arr[i]; // array
        xor1 = xor1 ^ (i+1); // numbers to be matched till n-1
      }
      xor1 = xor1 ^ N;
      
      return xor1 ^ xor2;
    }
};

int main() {
  vector<int> arr = {1,2,3,5,6,7,8,9,10};
  int n = 10;

  Solution s;
  
  // cout << s.missing(arr, n) << endl;

  // cout << s.missingByHashing(arr, n) << endl;

  // cout << s.missingBySum(arr, n) << endl;

  cout << s.missingByXOR(arr, n) << endl;
}