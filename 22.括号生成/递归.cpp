class Solution {
    vector<string> result;
    void _generate(string& str, int n, int left_n, int right_n)
    {
        if(left_n==n&&right_n==n) result.push_back(str);
        else if(left_n>n||right_n>left_n);
        else{
            str+='(';
            _generate(str,n,left_n+1,right_n);
            str.pop_back();
            str+=')';
            _generate(str,n,left_n,right_n+1);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string str;
        _generate(str,n,0,0);
        return result;
    }
};