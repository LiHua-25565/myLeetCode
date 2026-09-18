class Solution {
    int _upper_bound(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();
        while(left<right)
        {
            int mid = (left+right)/2;
            target < nums[mid] ? (right = mid) : (left = mid+1);
        }
        return left;
    }
    int _lower_bound(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();
        while(left<right)
        {
            int mid = (left+right)/2;
            nums[mid]<target? (left = mid+1) : (right = mid);
        }
        return left;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int u = _upper_bound(nums,target), l = _lower_bound(nums,target);
        if(u == l) return {-1,-1};
        return {l,u-1}; 
    }
};