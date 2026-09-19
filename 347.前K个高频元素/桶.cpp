class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. 统计频率
        unordered_map<int, int> freq;
        for (int x : nums) ++freq[x];

        int n = nums.size();
        // 2. 建桶，bucket[i] 存频率为 i 的所有元素
        vector<vector<int>> bucket(n + 1);
        for (auto& [val, f] : freq) {
            bucket[f].push_back(val);
        }

        // 3. 从高频到低频倒着取
        vector<int> result;
        for (int i = n; i >= 1 && (int)result.size() < k; --i) {
            for (int val : bucket[i]) {
                result.push_back(val);
                if ((int)result.size() == k) break;
            }
        }
        return result;
    }
};