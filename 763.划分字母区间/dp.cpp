class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> alphabet;
        for(char c:s) ++alphabet[c];
        vector<int> lengths;
        int i = 0;
        while(i<s.size())
        {
            int begin = i;
            unordered_map<char,int> curbet;
            bool can = true;
            do
            {
                can = true;
                ++curbet[s[i++]];
                for(auto& [a,b] : curbet) if(b<alphabet[a]) can = false;
            }while(!can);
            lengths.push_back(i-begin);
        }
        return lengths;
    }
};