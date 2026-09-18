class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n*m;
        while(left<right)
        {
            int mid = (left+right)/2;
            int x = mid/m,y = mid%m;
            matrix[x][y] < target ? (left = mid+1) : (right = mid);
        }
        if(!(left<n*m)) return false;
        return matrix[left/m][left%m] > target ? false : true;
    }
};