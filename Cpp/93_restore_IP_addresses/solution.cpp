class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.empty()) return res;
        string tmp(s);
        backtrace(res, tmp, 0, 0);
        return res;
    }
    
    void backtrace(vector<string>& res, string& tmp, int dots, int last)
    {
        if (dots == 3) 
        {
            if (checkValid(tmp)) res.push_back(tmp);
            return;
        }
        else if (last + 2 > tmp.size()) return;
        for (int i = last + 1; i < tmp.size() && i < last + 4; i ++)
        {
            tmp.insert(tmp.begin()+i, '.');
            backtrace(res, tmp, dots+1, i+1);
            tmp.erase(tmp.begin()+i);
        }
    }
    
    bool checkValid(string tmp)
    {
        stringstream ss(tmp);
        string cur;
        
        while (getline(ss, cur, '.'))
            if (cur.size() > 3 ||cur.size() != 1 && cur[0] == '0' || std::stoi(cur) > 255) return false;
        return true;    
    }
};