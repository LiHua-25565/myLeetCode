class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right_max(n,0);
        vector<int> left_max(n,0);
        int left_max_height = 0;
        int right_max_height = 0;
        for(int i = 0; i < n; i++)
        {
            left_max_height = max(left_max_height,height[i]);
            right_max_height = max(right_max_height,height[n-i-1]);
            left_max[i] = left_max_height;
            right_max[n-i-1] = right_max_height;
        }
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum+=min(right_max[i],left_max[i])-height[i];
        }
        return sum;
    }
};