// Move zeroes to end

#include <bits/stdc++.h>
using namespace std;

// T = O(4 * n) = O(n) --> In worst case
// S = O(n)
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) count++;
    }

    vector<int> arr;
    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            arr.push_back(nums[i]);
        }
    }

    while(count != 0) {
        arr.push_back(0);
        count--;
    }

    for(int i = 0; i < n; i++) {
        nums[i] = arr[i];
    }

    for(auto i : nums) cout << i << " ";
}

// T = O(n)
// S = O(1)
void moveZeroesOptimal(vector<int>& nums) {
    int n = nums.size();
    
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    while(j < n) {
        nums[j] = 0;
        j++;
    }

    for(auto i : nums) cout << i << " ";
}


// Leet code Solution -- Optimal

// T = O(n)
// S = O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                j = i;
                break;
            }
        }

        if(j == -1) return;
        for(int i = j + 1; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};


int main() {
    vector<int> nums = {0,1,2,0,2,5,0,5,7,8,0,4,0,7,1,2,4};

    moveZeroes(nums);
}