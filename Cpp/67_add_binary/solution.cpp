class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();
        int idx_a = 0;
        int idx_b = 0;
        int over = 0;
        int tmp;
        string res;
        
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        while (idx_a < len_a || idx_b < len_b)
        {
            if (idx_a >= len_a) tmp = b[idx_b ++] - '0' + over;
            else if (idx_b >= len_b) tmp = a[idx_a ++] - '0' + over;
            else tmp = (a[idx_a ++] - '0') + (b[idx_b ++] - '0') + over;
            over = tmp / 2;
            res.push_back(tmp % 2 + '0');
        }
        if (over) res.push_back('1');
        std::reverse(res.begin(), res.end());
        return res;
    }
};