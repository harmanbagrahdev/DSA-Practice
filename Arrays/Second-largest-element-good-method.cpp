// Second largest element in an array

#include <bits/stdc++.h>
using namespace std;

// T = O(2n)
// S = O(1)
int secLargest(vector<int>& nums, int n) {
    int largest = nums[0];
    int secondlargest = nums[0];

    for(int i = 0; i < n; i++) {
        if(nums[i] > largest) largest = nums[i];
    }

    for(int i = 0; i < n; i++) {
        if(nums[i] >= secondlargest && nums[i] < largest) secondlargest = nums[i];
    }
    return secondlargest;
}

// similar method can be used for second smallest element
// T = O(n)
// S = O(1)  
int secLargestOptimal(vector<int>& nums, int n) {
    // can also use : largest = INT_MIN, secondLargest = INT_MIN;   If all elements are non-negative, if they are negative then set these values to a very small negative number;
    int largest = nums[0];
    int secondLargest = nums[0];

    for(int i = 0; i < n; i++) {
        if(nums[i] > largest) {
            int temp = largest;
            largest = nums[i];
            secondLargest = temp;
        }

        else if(nums[i] > secondLargest) secondLargest = nums[i];
    }

    return secondLargest;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Second largest element : ";
    cout << secLargest(nums, n) << endl;

    cout << "Second largest element using optimal method : ";
    cout << secLargestOptimal(nums, n);
}