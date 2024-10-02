#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        // by brute force approach 
        int maxProfitByBruteForce(vector<int>& prices){
            int maxProfit = 0;
            for(int i = 0; i < prices.size(); i++){
                for(int j = i + 1; j < prices.size(); j++){ // Fixed j condition
                    int profit = prices[j] - prices[i];
                    maxProfit = max(maxProfit, profit);
                }
            }
            return maxProfit;
        }

        // using best approach
        int maxProfit(vector<int>& prices){
            if(prices.empty()) return 0;

            int minPrice = prices[0];
            int maxProfit = 0;

            for(int i = 1; i < prices.size(); i++){ // Start from 1 to avoid redundant checks
                if(prices[i] < minPrice){
                    minPrice = prices[i];
                } else {
                    maxProfit = max(maxProfit, prices[i] - minPrice);
                }
            }

            return maxProfit;
        }

        // auxiliary space approach
        int maxProfitByAuxiliary(vector<int>& prices){
            if(prices.empty()) return 0;

            vector<int> minPrices(prices.size()); // Auxiliary space to track minimum prices up to each day
            minPrices[0] = prices[0];

            // Populate the minPrices array
            for(int i = 1; i < prices.size(); i++) {
                minPrices[i] = min(minPrices[i - 1], prices[i]);
            }

            int maxProfit = 0;
            // Calculate the maximum profit
            for(int i = 1; i < prices.size(); i++) {
                maxProfit = max(maxProfit, prices[i] - minPrices[i]);
            }

            return maxProfit;
        }

        // optimized approach of maxProfit 
        int maxProfitOptimized(vector<int>& prices){
            if(prices.empty()) return 0;

            int minPrice = prices[0];
            int maxProfit  = 0;

            for(int i = 1; i < prices.size(); i++){ // Start from 1 for consistency
                minPrice = min(minPrice, prices[i]);
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }

            return maxProfit;
        }
};

int main(){
    Solution solution;
    vector<int>prices = {7, 1, 5, 3, 6, 4};  // Example prices
    int profit = 0;

    // brute force approach 
    profit = solution.maxProfitByBruteForce(prices);
    cout <<"Maximum Profit (Brute Force): " << profit << endl;

    // using best approach 
    profit = solution.maxProfit(prices);
    cout <<"Maximum Profit (Best Approach): " << profit << endl;

    // using auxiliary approach 
    profit = solution.maxProfitByAuxiliary(prices);
    cout <<"Maximum Profit (Auxiliary): " << profit << endl;

    // using Optimized approach 
    profit = solution.maxProfitOptimized(prices);
    cout <<"Maximum Profit (Optimized): " << profit << endl;

    return 0;
}
