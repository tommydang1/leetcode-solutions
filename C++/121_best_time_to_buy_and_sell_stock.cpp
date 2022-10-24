// Time: O(n)
// Space: O(1)

#include "header.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minCost = prices[0];
        
        for (int i = 0; i < prices.size(); i++) {
            minCost = min(minCost, prices[i]);
            profit = max(profit, prices[i] - minCost);
        }
        return profit;
    }
};