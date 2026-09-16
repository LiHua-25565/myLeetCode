class Solution {
    int n = 0, m = 0;
    void find_land(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y)
    {
        if(x<0||y<0||x>=n||y>=m||visited[x][y]||grid[x][y] == '0') return;
        visited[x][y] = true;
        int nx[4] = {0,1,0,-1},ny[4] = {1,0,-1,0};
        for(int i = 0; i < 4; ++i)
        {
            int ix = x+nx[i], iy = y+ny[i];
            find_land(grid, visited, ix, iy);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0;i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(visited[i][j]) continue;
                if(grid[i][j] == '1')
                {
                    ++result;
                    find_land(grid,visited,i,j);
                }
                visited[i][j] = true;
            }
        }
        return result;
    }
};