class Solution {
public:
    int trap(vector<int>& height) {
        std::stack<pair<int, int>> stk;
        stk.push({ height[0],0 });
        int sum = 0;
        for (int i = 1; i < height.size(); i++)
        {
            auto p = stk.top();
            int last_height = 0;
            while (!stk.empty() && p.first <= height[i])
            {
                stk.pop();
                sum += (p.first - last_height) * (i - p.second - 1);
                last_height = p.first;
                if (!stk.empty()) p = stk.top();
            }
            if (!stk.empty())
                sum += (height[i] - last_height) * (i - p.second - 1);
            stk.push({ height[i],i });
        }
        return sum;
    }
};