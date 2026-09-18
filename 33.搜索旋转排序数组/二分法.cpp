class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;

            if(nums[mid]<target)
            {
                if(nums[mid]<nums[0]&&target >= nums[0]) right = mid-1;
                else left = mid+1;
            }
            else
            {
                if(nums[mid]>=nums[0]&&target < nums[0]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};