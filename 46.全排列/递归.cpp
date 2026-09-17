class Solution {
    vector<vector<int>> result;
    void _permute(vector<int>& nums,vector<int>& vec)
    {
        if(vec.size() == nums.size())
        {
            result.push_back(vec);
        }
        else
        {
            for(int i = 0; i < nums.size(); ++i)
            {
                if(nums[i]!=11)
                {
                    int temp = nums[i];
                    nums[i] = 11;
                    vec.push_back(temp);
                    _permute(nums,vec);
                    vec.pop_back();
                    nums[i] = temp;
                }
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vec;
        _permute(nums,vec);
        return result;
    }
};