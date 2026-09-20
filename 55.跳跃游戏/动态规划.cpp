class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canjump = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(canjump >= nums.size()-1) return true;
            canjump = max(canjump,nums[i]+i);
            if(canjump == i) return false;
        }
        return true;
    }
};