class Solution {
    vector<string> result;
    const string letters[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void make_letter(string& str,string &digits)
    {
        if(str.size() == digits.size())
        {
            result.push_back(str);
        }
        else
        {
            int n = str.size();
            int num = digits[n]-'0';
            if(num==7||num==9)
            {
                for(int i =0 ; i < 4; ++i)
                {
                    str+=letters[num-2][i];
                    make_letter(str,digits);
                    str.pop_back();
                }
            }
            else 
            {
                for(int i =0 ; i < 3; ++i)
                {
                    str+=letters[num-2][i];
                    make_letter(str,digits);
                    str.pop_back();
                }
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string str;
        make_letter(str,digits);
        return result;
    }
};