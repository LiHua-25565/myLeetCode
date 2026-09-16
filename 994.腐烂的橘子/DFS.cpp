class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotted;
        int n = grid.size(), m = grid[0].size();
        const int nx[4] = {0,0,-1,1}, ny[4] = {-1,1,0,0}; 
        for(int i = 0; i < n ;++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j]==2) rotted.push({i,j});
            }
        }
        int time = -1;
        while(!rotted.empty())
        {
            int size = rotted.size();
            for(int i = 0; i < size; ++i)
            {
                auto it = rotted.front();
                rotted.pop();
                int x = it.first, y = it.second;
                for(int j = 0; j < 4; ++j)
                {
                    int jx = nx[j]+x, jy = ny[j]+y;
                    if(jx>=0 && jx<n && jy>=0 && jy<m && grid[jx][jy]==1)
                    {
                        rotted.push({jx,jy});
                        grid[jx][jy] = 2;
                    }
                }
            }
            ++time;
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return max(time,0);
    }
};