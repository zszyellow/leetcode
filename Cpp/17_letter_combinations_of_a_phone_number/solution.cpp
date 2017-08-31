class Solution {
public:
    map<int, string> m{
        {0, ""}, {1, ""}, {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
    };
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) return res;
        
        vector<string> tmp = letterCombinations(digits.substr(1, digits.size()-1));
        if (tmp.size() == 0) tmp.push_back("");
        for (int i = 0; i < m[digits[0]-'0'].size(); i++)
        {
            for (int j = 0; j < tmp.size(); j ++)
                res.push_back(m[digits[0]-'0'][i] + tmp[j]);
        }
        
        return res;
    }
};