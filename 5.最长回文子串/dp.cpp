class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1) return s;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int begin = 0, length = 1;
        for(int i = 0; i < n; ++i) 
        {
            for(int j = i; j < n; ++j) dp[j][i] = true;
        }
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(s[j] == s[i] && dp[j+1][i-1]) 
                {
                    dp[j][i] = true; 
                    if(length<i-j+1) length = i-j+1, begin = j;
                }
            }
        }
        cout<<begin;
        return s.substr(begin,length);
    }
};