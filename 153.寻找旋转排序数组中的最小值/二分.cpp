class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid]>=nums[0]) left = mid+1;
            else if(nums[mid] < nums[mid-1]) return nums[mid];
            else right = mid-1;
        }
        return nums[0];
    }
};