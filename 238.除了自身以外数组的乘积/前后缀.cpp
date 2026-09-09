class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> pre(n),follow(n);
        pre[0]=1;
        follow[n-1]=1;
        for(int i = 1;i < nums.size(); ++i)
        {
            pre[i] = pre[i-1]*nums[i-1];
            follow[n-1-i] = follow[n-i]*nums[n-i];
        }
        for(int i = 0; i < nums.size(); ++i) ans[i] = pre[i]*follow[i];
        return ans;
    }
};