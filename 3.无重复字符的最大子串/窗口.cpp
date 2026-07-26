class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n = s.size();
        int l = 0, r = 0;
        int length = 0, mlength = 0;
        while(r<n)
        {
            if(set.find(s[r])==set.end())
            {
                set.insert(s[r]);
                length++;
                mlength=max(mlength,length);
                r++;
            }
            else
            {
                set.erase(s[l]);
                length--;
                l++;
            }
        }
        return mlength;
    }
};