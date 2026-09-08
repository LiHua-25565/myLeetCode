class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left = 0, maxsum = nums[0], cursum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(cursum<0)
            {
                left = i;
                cursum = 0;
            }
            cursum+=nums[i];
            maxsum = max(maxsum,cursum);
        }
        return maxsum;
    }
};