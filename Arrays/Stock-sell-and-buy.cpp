// You are given an array of prices where prices[i] is the price of a given stock on an ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <bits/stdc++.h>
using namespace std;

// Brute Force
// T = O(n^2)
// S = O(1)
int stock(vector<int>& prices) {
  int n = prices.size();
  int maxProfit = 0;

  for(int i = 0; i < prices.size(); i++) {
    for(int j = i + 1; j < prices.size(); j++) {
      int profit = prices[j] - prices[i];

      maxProfit = max(maxProfit, profit);
    }
  }

  return maxProfit;
}

// DP : remembering past
// Optimal Solution
// T = O(n)
// S = O(1)
int stockBetter(vector<int>& prices) {
  int n = prices.size();
  int maxProfit = 0;
  int mini = prices[0];

  for(int i = 0; i < prices.size(); i++) {
    int cost = prices[i] - mini; // computing difference between elements of prices array
    maxProfit = max(maxProfit, cost);

    mini = min(mini, prices[i]); // tracking minimum buying price
  }

  return maxProfit;
}

int main() {
  vector<int> prices = {7,1,5,3,6,4};

  // cout << stock(prices) << endl;

  cout << stockBetter(prices) << endl;
}