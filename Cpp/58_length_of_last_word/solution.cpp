class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        vector<string> words;
        copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));
        if (words.empty()) return 0;
        else return words.back().size();
    }
};