两种情况，如果text2[j] == text1[i]，那么dp[i][j] = dp[i-1][j-1]+1
如果text2[j] != text1[i]，那么dp[i][j] = max(dp[i-1][j],dp[i][j-1])