class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, canjump = 0, jumptime = 0;
        while(canjump<nums.size()-1)
        {
            jumptime++;
            int curjump = canjump;
            for(;i<=curjump;++i)
            {
                canjump=max(canjump,i+nums[i]);
            }
        }
        return jumptime;
    }
};