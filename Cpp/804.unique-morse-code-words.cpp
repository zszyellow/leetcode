class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_table{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> representations;
        for (string& word : words) {
            string transformation;
            for (char& c : word) {
                transformation += morse_table[c - 'a'];
            }
            representations.insert(transformation);
        }
        return representations.size();
    }
};