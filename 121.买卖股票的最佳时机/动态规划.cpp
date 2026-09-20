class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, least = prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i]<least) least = prices[i];
            else if(prices[i]-least > profit) profit = prices[i]-least;
        }
        return profit;
    }
};