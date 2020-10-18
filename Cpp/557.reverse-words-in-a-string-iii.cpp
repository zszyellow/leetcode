class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0, L = s.size();
        for (int i = 0; i < L; ++ i) {
            if (s[i] == ' ') {
                end = i;
                std::reverse(s.begin()+start, s.begin()+end);
                start = end + 1;
            }
        }
        std::reverse(s.begin()+start, s.end());
        return s;
    }
};