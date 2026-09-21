class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        dp[0].push_back(1);
        for(int i = 1; i < numRows; ++i)
        {
            dp[i].push_back(1);
            for(int j = 0; j < dp[i-1].size()-1; ++j)
            {
                dp[i].push_back(dp[i-1][j]+dp[i-1][j+1]);
            }
            dp[i].push_back(1);
        }
        return dp;
    }
};