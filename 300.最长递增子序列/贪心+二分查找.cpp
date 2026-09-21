class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> d;
        d.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i)
        {
            int left = 0, right = d.size();
            while(left<right)
            {
                int mid = (left+right)/2;
                if(d[mid]<nums[i]) left = mid+1;
                else right = mid;
            }
            if(left == d.size()) d.push_back(nums[i]);
            else d[left] = nums[i];
        }
        return d.size();
    }
};  