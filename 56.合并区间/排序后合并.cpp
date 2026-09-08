class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        int left = intervals[0][0], right = intervals[0][1];
        for(vector<int> &vec:intervals)
        {
            if(vec[0]>right)
            {
                result.push_back({left,right});
                left = vec[0];
            }
            right = max(right,vec[1]);
        }
        result.push_back({left,right});
        return result;
    }
};