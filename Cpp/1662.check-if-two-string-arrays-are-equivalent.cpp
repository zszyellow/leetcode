class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "", str2 = "";
        for (string &chunk1 : word1) str1 += chunk1;
        for (string &chunk2 : word2) str2 += chunk2;
        return str1 == str2;
    }
};