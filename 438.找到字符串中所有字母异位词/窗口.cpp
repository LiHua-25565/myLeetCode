class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> map;
        for(char c:p) map[c]++;
        int l = 0, r = 0;
        vector<int> ans;
        while(r<s.size())
        {
            if(map[s[r]]>0)
            {
                map[s[r]]--;
                r++;
                if(r-l==p.size())
                {
                    ans.push_back(l);
                    map[s[l]]++;
                    l++;
                }
            }
            else
            {
                map[s[l]]++;
                l++;
            }
        }
        return ans;
    }
};