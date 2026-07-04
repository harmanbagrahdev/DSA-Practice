// Remove duplicates from sorted array

#include <bits/stdc++.h>
using namespace std;

// Leetcode -- need to return count of unique elements and modify original array's first k spaces with unique elements!
class Solution {
    public:
        // S = O(n)
        // T = O(n)
        int removeDuplicates(vector<int>& nums) {
            set<int> st;
            for(int i = 0; i < nums.size(); i++) {
                st.insert(nums[i]);
            }
    
            int i = 0;
            for(auto x : st) {
                nums[i++] = x;
            }
            return st.size();
        }
    };


// S = O(n) in worst case
// T = O(n)
void sortedArray(vector<int>& arr, int n) {
    set<int> st;
    for(int i = 0; i < n; i++) {
        st.insert(arr[i]); // O( n.log(n) )
    }

    // Print sorted array with unique elements
    for(auto i : st) {
        cout << i << " ";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Sorted array : ";
    sortedArray(arr, n);
    cout << endl;
}