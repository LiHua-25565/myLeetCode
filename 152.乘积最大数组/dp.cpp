class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxProd = nums[0];   // 以当前元素结尾的最大乘积
        long long minProd = nums[0];   // 以当前元素结尾的最小乘积
        long long result = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) swap(maxProd, minProd);   // 负数交换最大最小
            maxProd = max((long long)nums[i], maxProd * nums[i]);
            minProd = min((long long)nums[i], minProd * nums[i]);
            result = max(result, maxProd);
        }
        return (int)result;
    }
};