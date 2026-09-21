class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = 1;
        int max_lenghs = 1;
        for(int i = 1; i < n; ++i)
        {
            int longest = 0;
            for(int j = i-1; j >=0; --j) if(nums[j]<nums[i]) longest = max(longest,dp[j]);
            dp[i] = longest+1;
            max_lenghs=max(max_lenghs,dp[i]);
        }
        return max_lenghs;
    }
};