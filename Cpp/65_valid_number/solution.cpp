class Solution {
public:
    bool isNumber(string s) {
        return std::regex_match(s, std::regex("(\\s*)[+-]?((\\.[0-9]+)|([0-9]+(\\.[0-9]*)?))(e[+-]?[0-9]+)?(\\s*)"));
    }
};