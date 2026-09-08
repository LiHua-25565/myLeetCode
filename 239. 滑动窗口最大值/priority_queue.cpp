class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int,int>> pq;   //pair<value,index>
        for(int i = 0; i < nums.size() ; ++i)
        {
            pq.push({nums[i],i});
            if(i+1>=k)
            {
                while(pq.top().second<=i-k)
                    pq.pop();
                result.push_back(pq.top().first);
            }
        }
        return result;
    }
};