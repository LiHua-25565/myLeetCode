class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!dq.empty() && i - dq.front() >= k)
                dq.pop_front();

            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);
            if(i+1>=k)
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};