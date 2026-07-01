// Second largest element in an array

// review needed -- buggy algorithm needs to be fixed!
#include <bits/stdc++.h>
using namespace std;

void secLargest(vector<int>& nums, int n) {
    int largest = nums[0];
    int secondlargest = nums[0];

    for(int i = 0; i < n; i++) {
        if(nums[i] > largest) largest = nums[i];
        else if(secondlargest < largest && secondlargest != INT_MIN) {
            continue;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Second largest element : ";

}