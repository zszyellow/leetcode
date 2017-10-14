class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int len = s.size();
        vector<int> num(len+1, 0);
        num[len] = 1;
        num[len-1] = s[len-1] == '0' ? 0 : 1;
        
        for (int i = len - 2; i >= 0; i --)
        {
            if (s[i] == '0') continue;
            num[i] = std::stoi(s.substr(i, 2)) < 27 ? num[i+1]+num[i+2] : num[i+1]; 
        }
        return num[0];
    }
};