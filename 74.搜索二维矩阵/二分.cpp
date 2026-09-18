class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(! (matrix[0][0] < target)) return matrix[0][0] > target ? false : true;
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n*m;
        while(left<right-1)
        {
            int mid = (left+right)/2;
            int x = mid/m,y = mid%m;
            matrix[x][y] < target ? (left = mid) : (right = mid);
        }
        if(!(right < n*m)) return false;
        return matrix[right/m][right%m] > target ? false : true;
    }
};