class Solution {
    vector<vector<string>> result;
    void _partition(const string& s, vector<string>& vec,string& str, int index)
    {
        if(index == s.size())
        {
            if(str.size() == 0) result.push_back(vec);
        }
        else
        {
            str+= s[index];
            if(_is_palindrome(str))
            {
                vec.push_back(str);
                string str1;
                _partition(s,vec,str1,index+1);
                vec.pop_back();
            }
            _partition(s,vec,str,index+1);
            str.pop_back();
        }
    }
    bool _is_palindrome(const string& str)
    {
        int l = 0, r = str.size()-1;
        while(l<r)
        {
            if(str[l]!=str[r]) return false;
            ++l,--r;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        string str;
        _partition(s,vec,str,0);
        return result;
    }
};