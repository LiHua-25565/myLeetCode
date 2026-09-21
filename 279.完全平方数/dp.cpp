class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i*i<=n; ++i) squares.push_back(i*i);
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j:squares)
            {
                if(j>i) break;
                dp[i] = min(dp[i],dp[i-j]+1);
            }
        }
        return dp[n];
    }
};