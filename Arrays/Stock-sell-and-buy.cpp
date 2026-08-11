// You are given an array of prices where prices[i] is the price of a given stock on an ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n^2)
// S = O(1)
int stock(vector<int>& prices) {
  int n = prices.size();
  int maxProfit = 0;

  // Loop through each day as a potential buy day
  for(int i = 0; i < prices.size(); i++) {
    // Loop through each future day as a potential sell day
    for(int j = i + 1; j < prices.size(); j++) {
      // Calculate the profit
      int profit = prices[j] - prices[i];

      // Update max profit if this is higher
      maxProfit = max(maxProfit, profit);
    }
  }

  // Return the maximum profit
  return maxProfit;




  // int mini = 0;
  
  // for(int i = 0; i < n; i++) {
  //   if(arr[i] < arr[mini]) mini = i;
  // }
  
  // int maxi = mini;
  // for(int i = mini; i < n; i++) {
  //   if(arr[i] > arr[maxi]) maxi = i;
  // }

  // if(maxi > mini) return 0;

  // return arr[maxi];
  // //  - arr[mini];
}

int main() {
  vector<int> prices = {7,1,5,3,6,4};

  cout << stock(prices) << endl;
}