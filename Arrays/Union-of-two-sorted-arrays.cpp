#include <bits/stdc++.h>
using namespace std;

// brute force -- use a set and take union of two arrays in that set and then make that set a vector

// T = O(n1.log(n) + n2.log(n)) + log(n1 + n2)
// S = O(n1 +n2) + O(n1 +n2)
void unionArr(vector<int>& a, vector<int>& b) {
  set<int> s;
  // T = O(n1.log(n)) , where n and n1 --> size of set and size of array
  // S = O(n1)
  for(auto num : a) s.insert(num);
  
  // T = O(n2.log(n))
  // S = O(n2)
  for(auto num : b) s.insert(num);
  
  // T = O(n1 + n2)
  // S = O(n1 + n2)
  vector<int>(s.begin(), s.end());
  
  // S = O(n1 + n2) --> to display the answer
  for(auto i : s) {
    cout << i << " ";
  } cout << endl;
}


// optimal -- two pointer method

// T = O(n + m)
// S = O(n1 + n2) --> for returning answer only 
// auxiliary space --> S = O(1)
vector<int> unionArray(vector<int>& a, vector<int>& b) {
  int n = a.size();
  int m = b.size();
  int i = 0;
  int j = 0;
  vector<int> unionArr;

  while(i < n && j < m) {
    if(a[i] <= b[j]) {
      if(unionArr.empty() || unionArr.back() != a[i]) {
        unionArr.push_back(a[i]);
      }
      if(a[i] == b[j]) {
        j++;
      }
      
      i++;
    }

    else{
      if(unionArr.empty() || unionArr.back() != b[j]) {
        unionArr.push_back(b[j]);
      }
      j++;
    }
  }

  while(j < m) {
    if(unionArr.empty() || unionArr.back() != b[j]) {
      unionArr.push_back(b[j]);
    }
    j++;
  }

  while(i < n) {
    if(unionArr.empty() || unionArr.back() != a[i]) {
      unionArr.push_back(a[i]);
    }
    i++;
  }

  return unionArr;
}


int main() {
  vector<int> a = {1,2,3,4,5};
  vector<int> b = {4,5,6,7,8,9};

  // unionArr(a, b);

  vector<int> arr = unionArray(a, b);

  for(auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  // cout << "Program completed\n";
}