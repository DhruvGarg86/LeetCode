// Leet Code -> 121. Best Time to Buy and Sell Stock

// Q-121. You are given an array prices where prices[i] is the 
// price of a given stock on the ith day.

// // You want to maximize your profit by choosing a single 
// day to buy one stock and choosing a different day in the 
// future to sell that stock.

// // Return the maximum profit you can achieve from this 
// transaction. If you cannot achieve any profit, return 0.

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minprice = prices[0];
        int maxprofit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            int cost = prices[i] - minprice;
            maxprofit = max(maxprofit, cost);
            minprice = min(minprice, prices[i]);
        }
        return maxprofit;
    }
};