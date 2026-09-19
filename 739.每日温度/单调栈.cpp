class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.size() == 1) return {0};
        stack<int> stk;
        stk.push(0);
        vector<int> result(temperatures.size());
        for(int i = 1; i < temperatures.size(); ++i)
        {
            int curtem = temperatures[i];
            int tem = (temperatures[stk.top()]);
            while(curtem>tem)
            {
                result[stk.top()] = i-stk.top();
                stk.pop();
                if(stk.empty()) break;
                tem = temperatures[stk.top()];
            }
            stk.push(i);
        }
        return result;
    }
};