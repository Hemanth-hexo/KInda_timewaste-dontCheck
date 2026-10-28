#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        std::vector<int> hold(n, 0);
        std::vector<int> sold(n, 0);
        std::vector<int> rest(n, 0);
        
        hold[0] = -prices[0];
        sold[0] = 0;
        rest[0] = 0;
        
        for (int i = 1; i < n; ++i) {
            hold[i] = std::max(hold[i - 1], rest[i - 1] - prices[i]);
            sold[i] = hold[i - 1] + prices[i];
            rest[i] = std::max(rest[i - 1], sold[i - 1]);
        }
        
        return std::max(sold[n - 1], rest[n - 1]);
    }
};