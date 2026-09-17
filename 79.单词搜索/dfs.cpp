class Solution {
    int m;
    int n;
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int index, int x, int y)
    {
        static const int nx[4] = {-1,1,0,0}, ny[4] = {0,0,-1,1};
        if(index >= word.size()) return true;
        if(x<0||x>=m||y<0||y>=n||visited[x][y]||board[x][y]!=word[index]) return false;
        bool result = false;
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i)
        {
            int ix = x+nx[i],iy = y+ny[i];
            result = result || dfs(board,visited,word,index+1,ix,iy);
        }
        visited[x][y] = false;
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == word[0] && dfs(board,visited,word,0,i,j)) return true;
            }
        }
        return false;
    }
};