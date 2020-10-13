class Solution {
public:
    string toLowerCase(string str) {
        string res;
        for (char c : str) {
            if (c <= 'Z' && c >= 'A') res += (c + 32);
            else res += c;
        }
        return res;
    }
};