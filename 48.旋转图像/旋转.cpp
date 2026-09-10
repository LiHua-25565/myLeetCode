class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; ++i)
        {
            int end = n-i-1;
            for(int j = i; j < end; ++j)
            {
                swap(matrix[i][j],matrix[j][end]);
                swap(matrix[i][j],matrix[end][n-j-1]);
                swap(matrix[i][j],matrix[n-j-1][i]);
            }
        }
    }
};