class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left<right)
        {
            int mid = (left+right)/2;
            nums[mid]<target? (left = mid+1) : (right = mid);
        }
        return left;
    }
};