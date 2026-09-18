class Solution {
    int n;
    vector<vector<string>> result;
    vector<bool> col;
    vector<bool> leftup;
    vector<bool> rightup;
    void _push_string(vector<int>& vec)
    {
        vector<string> strs;
        for(int i = 0; i < n ;++i)
        {
            int v = vec[i];
            for(int j = 0; j < n; ++j)
            {
                if(v&1)
                {
                    string str1(j,'.'), str2(n-1-j,'.');
                    string str = str1 + "Q" + str2;
                    strs.push_back(str);
                    break;
                }
                v = v>>1;
            }
        }
        result.push_back(strs);
    }

    bool _can_place(vector<int>& vec,int x, int y)
    {
        if(col[y]||leftup[x+y]||rightup[n-1-y+x]) return false;
        return true;
    }

    void _solve(vector<int>& vec, int row)
    {
        if(row == vec.size())
        {
            _push_string(vec);
            return;
        }
        for(int i = 0; i < n; ++i)
        {
            if(!_can_place(vec,row,i)) continue;
            else
            {
                vec[row] = 1<<i;
                col[i] = true;
                leftup[i+row] = true;
                rightup[n-1-i+row] = true;
                _solve(vec,row+1);
                col[i] = false;
                leftup[i+row] = false;
                rightup[n-1-i+row] = false;
                vec[row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<int> vec(n,0);
        col.resize(n,false);
        leftup.resize(2*n-1,false);
        rightup.resize(2*n-1,false);
        _solve(vec,0);
        return result;
    }
};