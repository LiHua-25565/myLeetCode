class Solution {
    void stack_insert(std::stack<int>& stk1, int i)
    {
        std::stack<int> stk2;
        while(!stk1.empty() && stk1.top()>i)
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk1.push(i);
        while(!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
    void stack_pop(std::stack<int>& stk1, int i)
    {
        std::stack<int> stk2;
        while(!stk1.empty() && stk1.top()!=i)
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk1.pop();
        while(!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        std::stack<int> stk;
        for(int i = 0 ; i < k; i++) stack_insert(stk,nums[i]);
        vector<int> ans;
        ans.push_back(stk.top());
        for(int i = k ; i < n; i++)
        {
            stack_pop(stk,nums[i-k]);
            stack_insert(stk,nums[i]);
            ans.push_back(stk.top());
        }
        return ans;
    }
};