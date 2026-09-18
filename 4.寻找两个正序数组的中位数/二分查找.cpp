class Solution {
    double _findMedianSortedArrays(vector<int>& v1, vector<int>& v2)
    {
        int n = v1.size(), m = v2.size(), leftnum = (n+m+1)/2;
        int left = 0, right = m;
        while(left<=right)
        {
            int j = (left+right)/2;
            int i = leftnum-j;

            int leftmax1 = (i==0) ? INT_MIN : v1[i-1];
            int rightmin1 = (i==n) ? INT_MAX : v1[i];
            int leftmax2 = (j==0) ? INT_MIN : v2[j-1];
            int rightmin2 = (j==m) ? INT_MAX : v2[j];

            if(leftmax1<=rightmin2&&leftmax2<=rightmin1)
            {
                if((n+m)%2==0) return (max(leftmax1,leftmax2)+min(rightmin1,rightmin2))/2.0;
                else return max(leftmax1,leftmax2);
            }
            else if(leftmax2>rightmin1) right = j-1;
            else left = j+1;
        }
        return 0.0;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return nums1.size()>nums2.size() ? _findMedianSortedArrays(nums1,nums2) : _findMedianSortedArrays(nums2,nums1);
    }
};