class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left_max = height[0];
        int right_max = height[n-1];
        int pl=0,pr=n-1;
        int sum = 0;
        while(pr>=pl)
        {
            if(left_max<right_max)
            {
                sum+=left_max-height[pl];
                pl++;
                if(pl<n) left_max=max(left_max,height[pl]);
            }
            else
            {
                sum+=right_max-height[pr];
                pr--;
                if(pr>=0)right_max=max(right_max,height[pr]);
            }
        }
        return sum;
    }
};