class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size();
        while(--i>0 && nums[i]<=nums[i-1]);
        if(i==0) 
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int j = nums.size();
        while(nums[--j]<=nums[i-1]);
        swap(nums[j],nums[i-1]);
        reverse(nums.begin()+i,nums.end());
    }
};