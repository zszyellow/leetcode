class Solution {
public:
    string reformatNumber(string number) {
        string digits;
        for (char &c : number) {
            if (c >= '0' && c <= '9') digits += c;
        }
        
        int idx = 0, len = digits.size();
        string res;
        while (len - idx > 4) {
            res += digits.substr(idx, 3);
            res += '-';
            idx += 3;
        }
        
        if (len - idx == 0) 
            return res.substr(0, res.size()-1);
        else if (len - idx == 4) {
            res += digits.substr(idx, 2) + '-';
            res += digits.substr(idx+2);
            return res;
        }
        else {
            res += digits.substr(idx);
            return res;
        }
    }
};