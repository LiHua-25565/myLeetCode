class Solution {
    const string _push_stack(const string& s, int& index, int t)
    {
        if(index>=s.size()) return "";
        string str;
        while(index<s.size())
        {
            if(s[index] >= '0' && s[index] <= '9')
            {
                int T = s[index] - '0';
                while(s[++index] != '[')
                {
                    T = T*10 + s[index] - '0';
                }
                str += _push_stack(s,++index,T);
            }
            else if(s[index] == ']')
            {
                ++index;
                break;
            }
            else{
                str+=s[index];
                ++index;
            }
        }
        return _repeat(str,t);
    }
    const string _repeat(const string& str, int t)
    {
        string S;
        for(int i = 0; i < t;++i) S+=str;
        return S;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return _push_stack(s,i,1);
    }
};