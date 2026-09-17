class Solution {
    vector<vector<int>> result;
    void _combine(vector<int>& candidates, vector<int>& vec, int start, int k)
    {
        if(k==0)
        {
            result.push_back(vec);
            return;
        }
        for(int i = start; i < candidates.size(); ++i)
        {
            if(candidates[i]>k) break;
            vec.push_back(candidates[i]);
            _combine(candidates,vec,i,k-candidates[i]);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> vec;
        _combine(candidates,vec,0,target);
        return result;
    }
};