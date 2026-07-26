class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(i;i<n-2;i++)
        {
            if(i>0&&nums[i-1]==nums[i]) continue;
            int j = i+1, k = n-1;
            while(j<k)
            {
                int s = nums[i]+nums[j]+nums[k];
                if(s==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k&&nums[j+1]==nums[j])j++;
                    j++;
                    while(j<k&&nums[k-1]==nums[k])k--;
                    k--;
                }
                else if(s<0)
                {
                    while(j<k&&nums[j+1]==nums[j])j++;
                    j++;
                }
                else 
                {
                    while(j<k&&nums[k-1]==nums[k])k--;
                    k--;
                }
            }
        }
        return ans;
    }
};