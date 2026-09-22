class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int cnt = 0;
            for(int i:nums) cnt+= (i<=mid);
            if(cnt <= mid) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};