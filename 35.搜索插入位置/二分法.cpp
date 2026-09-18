class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left<right-1)
        {
            int mid = (left+right)/2;
            nums[mid]<target? (left = mid) : (right = mid);
        }
        return nums[left]<target?left+1:left;
    }
};