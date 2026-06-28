// Check if array is sorted

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> bubbleSort(vector<int> nums) {
            int n = nums.size();
    
            for(int i = 0; i <= n-1; i++) {
    
                for(int j = 0; j <= n-2; j++) {
                    if(nums[j] > nums[j+1]) {
                        swap(nums[j], nums[j+1]);
                    }
                }
            }
    
            return nums;
        }
    
        void leftRotate(vector<int>& nums) {
            int temp = nums[0];
            int n = nums.size();
            
            for(int i = 0; i < n-1; i++) {
                nums[i] = nums[i+1];
            }
            nums[n-1] = temp;
        }
    
        bool check(vector<int>& nums) {
            // Optimal soln
            // T = O(n)
            // s = (1)
            // Checks elements in circular order
            int n = nums.size();
    
            int disorder = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] > nums[(i + 1) % n]) disorder++;
            }
    
            if(disorder <= 1) return true;
            return false;
    
    
            // T = O(n^2)
            // S = O(n)
            // vector<int> compare = bubbleSort(nums);
    
            // for(int i = 1; i <= n; i++) {
            //     if(nums == compare) {
            //         return true;
            //     }
    
            //     if(nums != compare) {
            //         leftRotate(nums);
            //     }
            // }
            // return false;
    

            // --------  Not good -------------
            // int count = 0;
            // int disorder = 0;
            // for(int i = nums.size() - 1; i > 0; i--) {
            //     if(nums[i] >= nums[i-1]) count++;
            //     if(nums[i] < nums[i-1]) disorder++;
            // }
    
            // if(count == nums.size() && disorder == 0 || count == nums.size()-1 && disorder == 1) return true;
            // return false;
        }
    };

    int main() {
        vector<int> nums = {2,1,3,4};

        Solution s;

        cout << s.check(nums);
    }