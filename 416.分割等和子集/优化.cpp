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

        vector<bool> dp(target+1,false);
        dp[0] = true;
        for(int x : nums)
        {
            for(int j = target; j >= x; --j)
            {
                dp[j] = dp[j] || dp[j-x];
            }
        }
        return dp[target];
    }
};