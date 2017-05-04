class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size(), i = 2 * k, j;
        string res = "", tmp = "";
        if (!len) return res;
        for (; i < len; i += 2*k)
        {
            j = i - 2*k;
            tmp = s.substr(j, 2*k);
            reverse(tmp.begin(), tmp.begin()+k);
            res += tmp;
        }

        i -= 2*k;
        if (len - i < k)
        {
            tmp = s.substr(i, len-i);
            reverse(tmp.begin(), tmp.end());
            res += tmp;
        }
        else
        {
            tmp = s.substr(i, len-i);
            reverse(tmp.begin(), tmp.begin()+k);
            res += tmp;
        }

        return res;
    }
};
