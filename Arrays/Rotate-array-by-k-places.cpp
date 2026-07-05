// Rotate array by k places

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // T = O(k * n)
        void leftRotate(vector<int>& nums) {
            int n = nums.size();
            int temp = nums[n-1];
            
            for(int i = n-1; i > 0; i--) {
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
        }
    
        void rotate(vector<int>& nums, int k) {
            for(int i = 0; i < k; i++) {
                leftRotate(nums);
            }
        }
    };


// T = O(n)
// S = O(n)
void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> temp(n);
    
    for(int i = 0; i < n; i++) {
        temp[(i+k)%n] = nums[i];
    }

    for(auto i : temp) {
        cout << i << " ";
    }
}

// T = O(n) + O(k) + O(n-k) = O(2*n)
// S = O(1)
void rotateOptimal(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    // int i = 0, j = n-1;
    // while(i < j){
    //     swap(nums[i], nums[j]);
    //     i++;
    //     j--;
    // }

    // int p = 0, q = k-1;
    // while(p < q) {
    //     swap(nums[p], nums[q]);
    //     p++;
    //     q--;
    // }

    // int l = k, m = n-1;
    // while(l < m) {
    //     swap(nums[l], nums[m]);
    //     l++;
    //     m--;
    // }

    // This same can be done with reverse function!
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());

    for(auto i : nums) {
        cout << i << " ";
    }
}

int main() {
    int k = 3;
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10};
    // for(int i = 0; i < nums.size(); i++) {
    //     cin >> nums[i];
    // }

    rotateOptimal(nums, k);
}