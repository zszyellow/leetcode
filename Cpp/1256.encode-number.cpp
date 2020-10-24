class Solution {
public:
    string encode(int num) {
        string tmp = bitset<32>(num+1).to_string();
        return tmp.substr(tmp.find('1')+1);
    }
};