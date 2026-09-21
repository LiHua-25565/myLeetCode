class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,10001);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)
        {
            for(int j:coins)
            {
                if(j>i) break;
                dp[i] = min(dp[i],dp[i-j]+1);
            }
        }
        return dp[amount]>10000?-1:dp[amount];
    }
};