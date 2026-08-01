#include <bits/stdc++.h>
using namespace std;

// brute force --> take common elements from both arrays by comparing elements

// T = O(n * m)
// S = O(min(n,m))
vector<int> intersection(vector<int>& a, vector<int>& b) {
  vector<int> result;
  int n = a.size();
  int m = b.size();

  vector<int> visited(m, 0); // vector of size m initialized to 0
  for(int i = 0; i < n; i++) {

    for(int j = 0; j < m; j++) {
      if(a[i] == b[j] && visited[j] == 0) {
        result.push_back(a[i]);
        visited[j] = 1;
        break;
      }

      if(b[j] > a[i]) break; // break when element greater than a[i] is reached because you will not get intersection element in a sorted array
    }
  }

  return result;
}

// T = O(n+m) --> in worst case
// S = O(min(n,m)) --> including output
// S = O(1) --> Auxiliary space
vector<int> intersectionArr(vector<int>& a, vector<int>& b) {
  vector<int> array;
  int n = a.size();
  int m = b.size();

  int i = 0, j = 0;

  while(i < n && j < m) {
    if(a[i] < b[j]) {
      i++;
    }

    else if(a[i] > b[j]) {
      j++;
    }

    else {
      array.push_back(a[i]);
      i++;
      j++;
    }
  }

  return array;
}


int main() {
  vector<int> a = {1,2,3,3,4,5,6,7};
  vector<int> b = {3,3,5,6,7,8,9,10};

  // vector<int> result = intersection(a, b);

  vector<int> result = intersectionArr(a, b);

  for(auto i : result) {
    cout << i << " ";
  } cout << endl;
}