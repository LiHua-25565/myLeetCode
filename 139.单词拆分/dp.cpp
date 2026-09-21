class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); ++i)
        {
            unordered_set<int> candidate_lengths;
            for(int j = 1; j <= 20; ++j)
            {
                if(j>i) break;
                if(dp[i-j]) candidate_lengths.insert(j);
            }
            for(string& str:wordDict)
            {
                int length = str.size();
                if(candidate_lengths.count(length) && str == s.substr(i-length,length))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};