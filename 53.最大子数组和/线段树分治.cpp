class Solution {
    struct Status
    {
        int lsum;
        int rsum;
        int msum;
        int isum;
    };

    Status pushUp(vector<int>& nums, int left, int right)
    {
        if(left >= right) return {0,0,0,0};
        if(left == right-1)
        {
            int n = nums[left];
            return {n,n,n,n};
        }
        int m = (left+right)/2;
        Status s1,s2;
        s1=pushUp(nums,left,m);
        s2=pushUp(nums,m,right);
        int lsum = max(s1.lsum,s2.lsum+s1.isum);
        int rsum = max(s2.rsum,s1.rsum+s2.isum);
        int msum = max({lsum,rsum,s1.msum,s2.msum,s1.rsum+s2.lsum});
        int isum = s1.isum+s2.isum;
        return {lsum,rsum,msum,isum};
    }
public:
    int maxSubArray(vector<int>& nums) {
        return pushUp(nums,0,nums.size()).msum;
    }
};