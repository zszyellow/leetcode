class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hex("0123456789abcdef");
        string res = "";
        for (int i = 0; i < 8; ++ i) {
            res = hex[num & 0xf] + res;
            num >>= 4;
        }
        
        // remove leading zeros
        int cur = 0;
        while (true) {
            if (res[cur] != '0') break;
            else ++ cur;
        }
        return res.substr(cur);
    }
};