class Solution {
    pair<int,int> expand_from_center(string& s, int left, int right)
    {
        while(left>=0 && right < s.size() && s[left] == s[right]) --left, ++right;
        return {left+1,right-1};
    } 
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int begin = 0, length = 0;
        for(int i = 0; i < n; ++i)
        {
            auto[left1,right1] = expand_from_center(s,i,i);
            auto[left2,right2] = expand_from_center(s,i,i+1);
            if(right1-left1+1 > length)
            {
                begin = left1;
                length = right1-left1+1;
            }
            if(right2-left2+1>length)
            {
                begin = left2;
                length = right2-left2+1;
            }
        }
        return s.substr(begin,length);
    }
};