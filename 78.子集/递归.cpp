class Solution {
    vector<vector<int>> result;
    void _subsets(vector<int>& nums, vector<int>& vec, int n, int begin)
    {
        if(vec.size() == n)
        {
            result.push_back(vec);
        }
        if(n > nums.size()-begin+vec.size()) return;
        else
        {
            for(int i = begin; i < nums.size(); ++i)
            {
                if(nums[i]<11)
                {
                    int temp = nums[i];
                    nums[i] = 11;
                    vec.push_back(temp);
                    _subsets(nums,vec,n,i+1);
                    vec.pop_back();
                    nums[i] = temp;
                }
            }
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back(vector<int>());
        for(int i =0 ; i < nums.size();++i)
        {
            vector<int> vec;
            _subsets(nums,vec,i+1,0);
        }
        return result;
    }
};