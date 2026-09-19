class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),maxV = 0;
        stack<int> stk;
        stk.push(-1);
        for(int i = 0; i <= n; ++i)
        {
            int h = (i==n) ? 0 : heights[i];
            while(stk.top() > -1 && heights[stk.top()] >= h)
            {
                int height = heights[stk.top()];
                stk.pop();
                int width = i - stk.top() - 1;
                maxV = max(maxV,height*width);
            }
            stk.push(i);
        }        
        return maxV;
    }
};