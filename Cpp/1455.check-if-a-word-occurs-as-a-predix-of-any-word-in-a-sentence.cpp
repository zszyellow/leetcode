class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        /* Using stringstream */
//         istringstream iss(sentence);
//         vector<string> words(istream_iterator<string>{iss}, istream_iterator<string>());

//         auto it = find_if(words.begin(), words.end(), [&](string &word) -> bool {
//            return word.size() >= searchWord.size() && 
//                   word.substr(0, searchWord.size()) == searchWord;
//         });
//         return it == words.end() ? -1 : it - words.begin() + 1;
        
        /* Using getline() */
        string token;
        istringstream iss(sentence);
        int res = 1;
        while (getline(iss, token, ' ')) {
            if (token.size() >= searchWord.size() && token.substr(0, searchWord.size()) == searchWord)
                return res; 
            res ++;
        }
        return -1;
    }
};