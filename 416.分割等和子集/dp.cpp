class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false;
        int sum = 0; 
        int max_num = 0;
        for(int i : nums) sum+=i, max_num = max(i,max_num);
        int target = sum/2;
        if(sum%2) return false;
        if(max_num>target) return false;

        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(auto &vec : dp) vec[0] = true;
        dp[0][nums[0]] = true;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 1; j <= target; ++j)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i]) dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][target];
    }
};