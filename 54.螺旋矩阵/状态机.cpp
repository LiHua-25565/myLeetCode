class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int up = -1, down = matrix.size(), left = -1, right = matrix[0].size();
        int i=0,j=0,statu = 0;
        vector<int> result;
        while(true)
        {
            result.push_back(matrix[i][j]);
            if(statu == 0)
            {
                if(j==right-1)
                {
                    ++up;
                    statu = 1;
                    if(++i==down) break;
                }
                else ++j;
            }
            else if(statu == 1)
            {
                if(i==down-1)
                {
                    --right;
                    statu = 2;
                    if(--j==left) break;
                }
                else ++i;
            }
            else if(statu == 2)
            {
                if(j==left+1)
                {
                    --down;
                    statu = 3;
                    if(--i==up) break;
                }
                else --j;
            }
            else if(statu == 3)
            {
                if(i==up+1)
                {
                    ++left;
                    statu = 0;
                    if(++j==right) break;
                }
                else --i;
            }
        }
        return result;
    }
};