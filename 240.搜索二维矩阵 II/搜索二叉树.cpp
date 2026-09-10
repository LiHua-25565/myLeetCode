class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        int i = r-1, j = 0;
        while(j<c && i>=0)
        {
            if(target < matrix[i][j]) --i;
            else if(target > matrix[i][j]) ++j;
            else return true;
        }
        return false;
    }
};