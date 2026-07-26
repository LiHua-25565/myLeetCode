class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = 1;
        int ans = 0, pre = 0;
        for(int i:nums)
        {
            pre+=i;
            if(map.find(pre-k)!=map.end())
            {
                ans+=map[pre-k];;
            }
            map[pre]++;
        }
        return ans;
    }
};