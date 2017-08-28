class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;
    
        int result = 0;
        map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        // find the special sequences and do the preprocess, they all would be appear once or never
        if (s.find("CD") != std::string::npos) result -= 200;
        if (s.find("CM") != std::string::npos) result -= 200;
        if (s.find("XL") != std::string::npos) result -= 20;
        if (s.find("XC") != std::string::npos) result -= 20;
        if (s.find("IV") != std::string::npos) result -= 2;
        if (s.find("IX") != std::string::npos) result -= 2;
        
        // calculate the sum
        for (auto it = s.begin(); it != s.end(); it ++) result += m[*it];
        
        return result;
    }
};