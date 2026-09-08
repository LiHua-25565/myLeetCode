class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        else if(s==t) return s;

        unordered_map<char,int> need, window;
        for(char c : t) ++need[c];
        list<int> l;
        int valid = 0;
        int start = -1;
        int minlen = 2147483647;

        for(int i = 0; i < s.size(); ++i)
        {
            if(need.find(s[i])!=need.end())
            {
                ++window[s[i]];
                l.push_back(i);
                
                if(window[s[i]]==need[s[i]]) valid++;

                while(valid == need.size())
                {
                    int left = l.front();
                    if(i-left+1<minlen)
                    {
                        minlen = i-left+1;
                        start = left;
                    }
                    --window[s[left]];
                    l.pop_front();
                    if(window[s[left]]<need[s[left]]) --valid;
                }
            }
        }

        if(start >= 0) return s.substr(start,minlen);
        return "";
    }
};