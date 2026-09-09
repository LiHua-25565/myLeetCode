class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        if(k==0) return;
        vector<int> temp(k);
        auto mid = nums.begin()+nums.size()-k;
        copy(mid,nums.end(),temp.begin());
        copy(nums.begin(),mid,nums.begin()+k);
        copy(temp.begin(),temp.end(),nums.begin());
    }
};