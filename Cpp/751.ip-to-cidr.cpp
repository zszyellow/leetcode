class Solution {
public: 
    vector<string> ipToCIDR(string ip, int n) {
        long start = ipToLong(ip);
        vector<string> res;        
        while (n > 0) {
            int x = start & (-start);
            int mask = max(33 - bitLength(x), 33 - bitLength(n));
            res.push_back(longToIP(start) + "/" + to_string(mask));
            start += 1 << (32 - mask);
            n -= 1 << (32 - mask);
        }
        return res;
    }
    
    long ipToLong(string ip) {
        long res = 0;
        string tmp; 
        istringstream iss(ip);
        while(getline(iss, tmp, '.')) {
            res = 256 * res + stoi(tmp);
        }
        return res;
    }

    string longToIP(long x) {
        return (to_string(x >> 24) + "." + to_string((x >> 16) % 256) + "." + to_string((x >> 8) % 256) + "." + to_string(x % 256));
    }

    int bitLength(long x) {
        if (x == 0) return 1;
        int res = 0;
        while (x) {
            x >>= 1;
            res ++;
        }
        return res;
    }
};