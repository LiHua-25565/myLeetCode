class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), max_length = 0;
        if(n<2) return max_length;
        vector<int> dp(n);
        for(int i = 1; i < n; ++i)
        {
            if(s[i] == '(') continue;
            if(i>=dp[i-1]+1)
            {
                if(s[i-1] == ')')
                {
                    int j = i-1-dp[i-1];
                    if(s[j] == '(') dp[i] = dp[i-1] + 2 +(j>=1?dp[j-1]:0); 
                }
                else dp[i] = (i<2) ? 2 : dp[i-2] + 2;
            }
            max_length = max(max_length,dp[i]);
        }
        return max_length;
    }
};